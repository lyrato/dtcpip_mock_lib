AUTOMAKE_OPTIONS = subdir-objects
#bin_PROGRAMS = dtcpip_mock_lib
lib_LTLIBRARIES=libdtcpip.la
libdtcpip_la_SOURCES = \
                        MockDLL.c \
                        MockDLL.h \
                        mpe_error.h \
                        mpe_types.h \
                        os_error.h \
                        os_util_common.h
libdtcpip_la_LDFLAGS = -version-info 1:0:0
if LINUX
AM_CPPFLAGS = -I$(srcdir) -I$(srcdir)/linux -I$(srcdir)/linux/include
libdtcpip_la_SOURCES += \
                           linux/mock_sync.h \
                           linux/mock_sync.c \
                           linux/include/os_types.h \
                           linux/include/os_sync.h
libdtcpip_la_CFLAGS = -pthread
else
AM_CPPFLAGS = -I$(srcdir) -I$(srcdir)/win32 -I$(srcdir)/win32/include
libdtcpip_la_SOURCES += \
                           win32/mock_sync.h \
                           win32/mock_sync.c \
                           win32/include/os_types.h \
                           win32/include/os_sync.h
endif

