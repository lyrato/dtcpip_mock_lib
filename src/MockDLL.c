// COPYRIGHT_BEGIN
//  DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
//
//  Copyright (C) 2008-2011, Cable Television Laboratories, Inc.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, version 2. This program is distributed
//  in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
//  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE. See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program.  If not, see  <http://www.gnu.org/licenses/>.
//
//  Please contact CableLabs if you need additional information or
//  have any questions.
//
//      CableLabs
//      858 Coal Creek Cir
//      Louisville, CO 80027-9750
//      303 661-9100
//      oc-mail@cablelabs.com
//
//  If you or the company you represent has a separate agreement with CableLabs
//  concerning the use of this code, your rights and obligations with respect
//  to this code shall be as set forth therein. No license is granted hereunder
//  for any other purpose.
// COPYRIGHT_END


#include "mock_sync.h"

#include <stdio.h>
#include <string.h> // memcpy, strrchr, strlen
#include <stdlib.h>

#if defined( WIN32 )
    #define snprintf _snprintf
#endif


#include "MockDLL.h"

#define DTCPIP_SERVER_SESSION_START 65536
#define DTCPIP_SERVER_SESSIONS_MAX  sizeof(uint32_t)

static struct
{
    mock_Mutex mutex;
    uint32_t  sessions;
}
server_data;



int dtcpip_cmn_init(const char* storage_path)
{
    return 0;
}

void dtcpip_cmn_get_version(char* string, size_t length)
{
    snprintf(string, length, "NO-OP DTCP-IP library for OCAP Reference Implementation.");
}

int dtcpip_src_init(unsigned short dtcp_port)
{
    int ret_code = -1;

    if (mock_mutexNew(&server_data.mutex) != MPE_SUCCESS)
    {
        ret_code = -2;
    }
    else
    {
        ret_code = 0;
    }

    return ret_code;
}

int dtcpip_src_open(int* session_handle, int is_audio_only)
{
    int ret_code = -1;


    if (session_handle == NULL)
    {
        ret_code = -2;
    }
    else
    {
        int i = 0;
        uint32_t session = 0;

        mock_mutexAcquire(server_data.mutex);

        for (i = 0; i < DTCPIP_SERVER_SESSIONS_MAX; i++)
        {
            session = 1 << i;
            if ((server_data.sessions & session) == 0)
            {
                break;
            }
        }

        if (i == DTCPIP_SERVER_SESSIONS_MAX)
        {
            ret_code = -3;
        }
        else
        {
            server_data.sessions ^= session;
            *session_handle = (int) (DTCPIP_SERVER_SESSION_START + i);
            ret_code = 0;
        }
        mock_mutexRelease(server_data.mutex);
    }

    return ret_code;
}

int dtcpip_src_alloc_encrypt(int session_handle,
                 unsigned char cci,
                 char* cleartext_data, size_t cleartext_size,
                 char** encrypted_data, size_t* encrypted_size)
{
    int ret_code = -1;

    uint32_t session = 1 << ((uint32_t) session_handle - DTCPIP_SERVER_SESSION_START);

    mock_mutexAcquire(server_data.mutex);

    if ((server_data.sessions & session) == 0)
    {
        ret_code = -2;
    }
    else if (cleartext_data == NULL && cleartext_size > 0) // only read if we have data
    {
        ret_code = -3;
    }
    else if (encrypted_data == NULL && cleartext_size > 0) // only written if we have data
    {
        ret_code = -4;
    }
    else if (encrypted_size == NULL) // always written
    {
        ret_code = -5;
    }
    else if (cleartext_size == 0)
    {
        *encrypted_size = 0;
        ret_code = 0;
    }
    else if ((*encrypted_data = malloc(cleartext_size)) == NULL)
    {
        ret_code = -6;
    }
    else
    {
        memcpy(*encrypted_data, cleartext_data, cleartext_size);
        *encrypted_size = cleartext_size;
        ret_code = 0;
    }

    mock_mutexRelease(server_data.mutex);

    return ret_code;
}

int dtcpip_src_free(char* encrypted_data)
{
    free(encrypted_data);
    return 0;
}

int dtcpip_src_close(int session_handle)
{
    int ret_code = -1;

    uint32_t session = 1 << ((uint32_t) session_handle - DTCPIP_SERVER_SESSION_START);


    mock_mutexAcquire(server_data.mutex);

    if ((server_data.sessions & session) == 0)
    {
        ret_code = -2;
    }
    else
    {
        server_data.sessions ^= session;
        ret_code = 0;
    }

    mock_mutexRelease(server_data.mutex);

    return ret_code;
}

#define DTCPIP_PLAYER_SESSION_START 16777216
#define DTCPIP_PLAYER_SESSIONS_MAX  sizeof(uint32_t)

static struct
{
    mock_Mutex mutex;
    uint32_t  sessions;
}
player_data;

int dtcpip_snk_init(void)
{
    int ret_code = -1;

    if (mock_mutexNew(&player_data.mutex) != MPE_SUCCESS)
    {
        ret_code = -2;
    }
    else
    {
        player_data.sessions = 0;
        ret_code = 0;
    }

    return ret_code;
}

int dtcpip_snk_open(
                 char* ip_addr, unsigned short ip_port,
                 int *session_handle)
{
    int ret_code = -1;

    if (ip_addr == NULL)
    {
        ret_code = -2;
    }
    else if (session_handle == NULL)
    {
        ret_code = -3;
    }
    else
    {
        int i = 0;
        uint32_t session = 0;

        mock_mutexAcquire(player_data.mutex);

        for (i = 0; i < DTCPIP_PLAYER_SESSIONS_MAX; i++)
        {
            session = 1 << i;
            if ((player_data.sessions & session) == 0)
            {
                break;
            }
        }

        if (i == DTCPIP_PLAYER_SESSIONS_MAX)
        {
            ret_code = -4;
        }
        else
        {
            player_data.sessions ^= session;
            *session_handle = (int) (DTCPIP_PLAYER_SESSION_START + i);
            ret_code = 0;
        }
        mock_mutexRelease(player_data.mutex);
    }

    return ret_code;
}

int dtcpip_snk_alloc_decrypt(int session_handle,
                 char* encrypted_data, size_t encrypted_size,
                 char** cleartext_data, size_t* cleartext_size)
{
    int ret_code = -1;

    uint32_t session = 1 << ((uint32_t) session_handle - DTCPIP_PLAYER_SESSION_START);

    mock_mutexAcquire(player_data.mutex);

    if ((player_data.sessions & session) == 0)
    {
        ret_code = -2;
    }
    else if (encrypted_data == NULL && encrypted_size > 0) // only read if we have data
    {
        ret_code = -3;
    }
    else if (cleartext_data == NULL && encrypted_size > 0) // only written if we have data
    {
        ret_code = -4;
    }
    else if (cleartext_size == NULL) // always written
    {
        ret_code = -5;
    }
    else if (encrypted_size == 0)
    {
        *cleartext_size = 0;
        ret_code = 0;
    }
    else if ((*cleartext_data = malloc(encrypted_size)) == NULL)
    {
        ret_code = -6;
    }
    else
    {
        memcpy(*cleartext_data, encrypted_data, encrypted_size);
        *cleartext_size = encrypted_size;
        ret_code = 0;
    }

    mock_mutexRelease(player_data.mutex);

    return ret_code;
}

int dtcpip_snk_free(char* cleartext_data)
{
    free(cleartext_data);
    return 0;
}

int dtcpip_snk_close(int session_handle)
{
    int ret_code = -1;

    uint32_t session = 1 << ((uint32_t) session_handle - DTCPIP_PLAYER_SESSION_START);

    mock_mutexAcquire(player_data.mutex);

    if ((player_data.sessions & session) == 0)
    {
        ret_code = -2;
    }
    else
    {
        player_data.sessions ^= session;
        ret_code = 0;
    }

    mock_mutexRelease(player_data.mutex);

    return ret_code;
}

unsigned int dtcpip_get_encrypted_sz(unsigned int cleartextSz, unsigned int basePCPPayload)
{
    unsigned int nBasePacketPadding = 16 - basePCPPayload % 16;
    if (nBasePacketPadding == 16)
    {
        nBasePacketPadding = 0;
    }
    unsigned int nBasePacketSz = basePCPPayload + nBasePacketPadding + 14 /* header */;
    

    unsigned int nLeftoverBytes = cleartextSz % basePCPPayload;
    unsigned int nNumBasePackets = (cleartextSz - nLeftoverBytes) / basePCPPayload;
    unsigned int nLeftoverPadding = 16 - nLeftoverBytes % 16;
    if (nLeftoverPadding == 16)
    {
        nLeftoverPadding = 0;
    }

    unsigned int nLeftoverPacketSz = nLeftoverBytes + nLeftoverPadding + 14 /* header */;

    unsigned int encryptedSz = nNumBasePackets * nBasePacketSz;
    if (nLeftoverBytes != 0)
    {
        encryptedSz += nLeftoverPacketSz;
    }

    return encryptedSz;
}

