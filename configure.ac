dnl Process this file with autoconf to produce a configure script.
AC_INIT(src/lors_exnode.c)

dnl Checks for system
AC_CANONICAL_SYSTEM

dnl automake and header files
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE( [lors], [2.0] )
AC_PREFIX_DEFAULT("`pwd`/local")
AC_CONFIG_MACRO_DIR([config])

case "$build_os" in 
linux*)
	OSTYPE="Linux" 
    OSDEF="_LINUX"
    EXTRA_CFLAGS=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE 
    ;;
solaris*)
	OSTYPE="SunOS"
    OSDEF="_SUNOS"
    EXTRA_CFLAGS=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE 
    ;;
sunos*)
	OSTYPE="SunOS"
    OSDEF="_SUNOS"
    EXTRA_CFLAGS=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE 
    ;;
aix*)
	OSTYPE="AIX"
    OSDEF="_AIX"
    EXTRA_CFLAGS=-D_LARGE_FILES -DLARGE_FILE_API
    ;;
macos*)
	OSTYPE="Darwin"
    OSDEF="_MACOS"
    EXTRA_CFLAGS=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE 
    ;;
darwin*)
	OSTYPE="Darwin"
    OSDEF="_DARWIN"
    EXTRA_CFLAGS=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE  -faltivec -no-cpp-precomp
    ;;
cygwin*)
	OSTYPE="Cygwin" 
    OSDEF="_CYGWIN"
    EXTRA_CFLAGS=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE 
    ;;
mingw*)
	OSTYPE="Mingw" 
    OSDEF="_MINGW"
    EXTRA_CFLAGS = -mconsole -lws2_32 -lpthreadGC
    ;;
esac

AC_SUBST(OSTYPE)
AC_SUBST(OSDEF)
AC_SUBST(EXTRA_CFLAGS)
AC_SUBST(LIBS)

AC_DEFUN(AC_FIND_FILE,
[AC_MSG_CHECKING( for $1)
if test -r $1; then
    AC_MSG_RESULT(found)
    $2
else
    AC_MSG_RESULT(no)
    $3
fi])


dnl Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PATH_PROGS(XML2CONFIG, xml2-config)

dnl Checks for libraries.
dnl AC_CHECK_LIB(des, des_options)
dnl AC_CHECK_LIB(md5, MD5Init)
AC_CHECK_LIB(pthread, pthread_create)
AC_CHECK_LIB(socket,socket)
AC_CHECK_LIB(nsl,gethostbyname)
AC_CHECK_LIB(m,log)
AC_CHECK_LIB(uuid,uuid_generate, ,AC_MSG_ERROR("Can not find libuuid"))

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(fcntl.h limits.h malloc.h sgtty.h sys/ioctl.h sys/time.h termio.h unistd.h)

dnl checks for gcc include directory
if test "${CC}" = "gcc" ;
then
    GCC_INC_DIR="`${CC} -print-libgcc-file-name`"
    GCC_INC_DIR="`dirname ${GCC_INC_DIR}`"
    GCC_INC_DIR=${GCC_INC_DIR}/include
fi
AC_SUBST(GCC_INC_DIR)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_HEADER_TIME
AC_STRUCT_TM

dnl Checks for library functions.
AC_FUNC_MEMCMP
AC_TYPE_SIGNAL
AC_FUNC_STRFTIME
AC_FUNC_VPRINTF
AC_CHECK_FUNCS(ftime gettimeofday select strdup strerror strspn strstr)


PREFIX="`pwd`"

if test "$prefix" = "NONE"; then
    INS_DIR="$ac_default_prefix"
else
    INS_DIR="$prefix"
fi


dnl check and setup path of popt package
AC_ARG_WITH(popt,[--with-popt=path   path to popt package(default is /usr)],
            LORS_POPT_DIR="$with_popt",
            LORS_POPT_DIR="/usr")

AC_FIND_FILE("${LORS_POPT_DIR}/include/popt.h",
            LORS_BUILD_POPT="no",
            AC_FIND_FILE("${PREFIX}/popt/popt.c",
                          LORS_BUILD_POPT="yes"
                          LORS_POPT_SRC_DIR="${PREFIX}/popt"
                          LORS_POPT_DIR="${INS_DIR}",
                          AC_MSG_ERROR("Can not find popt package")))
AC_SUBST(LORS_BUILD_POPT)
AC_SUBST(LORS_POPT_DIR)
AC_SUBST(LORS_POPT_SRC_DIR)

dnl check and setup path of zlib package
AC_ARG_WITH(zlib,[--with-zlib=path   path to zlib package(default is /usr)],
            LORS_ZLIB_DIR="$with_zlib",
            LORS_ZLIB_DIR="/usr")

AC_FIND_FILE("${LORS_ZLIB_DIR}/include/trees.h",
            LORS_BUILD_ZLIB="no",
            AC_FIND_FILE("${PREFIX}/zlib/trees.c",
                          LORS_BUILD_ZLIB="yes"
                          LORS_ZLIB_SRC_DIR="${PREFIX}/zlib"
                          LORS_ZLIB_DIR="${INS_DIR}",
                          AC_MSG_ERROR("Can not find zlib package")))
AC_SUBST(LORS_BUILD_ZLIB)
AC_SUBST(LORS_ZLIB_DIR)
AC_SUBST(LORS_ZLIB_SRC_DIR)

dnl check and setup path of libxml2 package 
AC_ARG_WITH(libxml2,[--with-libxml2=path         path to libxml2[default=/usr]],
            LORS_XML2_DIR="$with_libxml2",
            LORS_XML2_DIR="/usr")
AC_FIND_FILE("${LORS_XML2_DIR}/include/libxml2/libxml/tree.h",
            LORS_BUILD_XML2="no",
            AC_FIND_FILE("${PREFIX}/libxml2/tree.c",
                          LORS_BUILD_XML2="yes"
                          LORS_XML2_SRC_DIR="${PREFIX}/libxml2"
                          LORS_XML2_DIR="${INS_DIR}",
                          AC_MSG_ERROR("Can not find libxml2 package")))
AC_SUBST(LORS_BUILD_XML2)
AC_SUBST(LORS_XML2_DIR)
AC_SUBST(LORS_XML2_SRC_DIR)

dnl check for libjansson package
AC_ARG_WITH(libjansson, [--with-libjansson=path   path to libjansson], ,
            with_libjansson=no)
if test "$with_libjansson" == "no"; then
   AC_CHECK_LIB([jansson], [json_object], ,AC_MSG_ERROR([Can not buiild without libjansson]))		
else
   AC_MSG_CHECKING( for libjansson)
   if test -f "$with_libjansson/include/jansson.h"; then
   	   AC_MSG_RESULT(yes)
	   AC_SUBST(LIBJANSSON_INC, "-I$with_libjansson/include")
	   AC_SUBST(LIBJANSSON_LIB, "-L$with_libjansson/lib -ljansson")
   else
	   AC_MSG_RESULT(no)
	   AC_MSG_ERROR([Can not buiild without libjansson])
   fi
fi

dnl check for libunis-c package
AC_ARG_WITH(libunis, [--with-libunis=path   path to libunis-c], ,
            with_libunis=no)
if test "$with_libunis" == "no"; then
   PKG_CHECK_MODULES([LIBUNIS], [libunis-c], [], [AC_MSG_ERROR([Can not buiild without libunis-c])])
   AC_SUBST(LIBUNIS_INC, "$LIBUNIS_CFLAGS")
   AC_SUBST(LIBUNIS_LIB, "$LIBUNIS_LIBS")
else
   AC_MSG_CHECKING(for libunis)
   
   if test -f "$with_libunis/include/unis_exnode.h"; then
   	   AC_MSG_RESULT(yes)
	   AC_SUBST(LIBUNIS_INC, "-I$with_libunis/include")
	   AC_SUBST(LIBUNIS_LIB, "-L$with_libunis/lib -lunis-c")
   else
	   AC_MSG_RESULT(no)
	   AC_MSG_ERROR([Can not buiild without libunis])
   fi
fi

dnl check for libwebscokets package
AC_ARG_WITH(libwebsockets, [--with-libwebsockets=path   path to libwebsockets], ,
            with_libwebsockets=no)
if test "$with_libwebsockets" == "no"; then
   AC_CHECK_LIB([websockets], [lws_create_context], ,AC_MSG_ERROR([Can not buiild without libwebsockets]))
else
   AC_MSG_CHECKING( for libwebsockets)
   if test -f "$with_libwebsockets/include/libwebsockets.h"; then
   	   AC_MSG_RESULT(yes)
	   AC_SUBST(LIBWEBSOCKETS_INC, "-I$with_libwebsockets/include")
	   AC_SUBST(LIBWEBSOCKETS_LIB, "-L$with_libwebsockets/lib -lwebsockets")
   else
	   AC_MSG_RESULT(no)
	   AC_MSG_ERROR([Can not buiild without libwebsockets])
   fi
fi

dnl check and setup path of lbone package
AC_ARG_WITH(lbone,[--with-lbone=path    path to lbone package],
            LORS_LBONE_DIR="$with_lbone",
            LORS_LBONE_DIR="${INS_DIR}")
AC_FIND_FILE("${LORS_LBONE_DIR}/lib/liblbone.a",
            LORS_BUILD_LBONE="no",
            AC_FIND_FILE("${PREFIX}/lbone/client/include/lbone_base.h",
                        LORS_BUILD_LBONE="yes"
                        LORS_LBONE_DIR="${INS_DIR}"
                        LORS_LBONE_SRC_DIR="${PREFIX}/lbone",
                        AC_MSG_ERROR("Can not find lbone package")))
AC_SUBST(LORS_BUILD_LBONE)
AC_SUBST(LORS_LBONE_SRC_DIR)
AC_SUBST(LORS_LBONE_DIR)


dnl check and setup path of libexnode package
AC_ARG_WITH(libexnode, [--with-libexnode=path      path to libexnode],
            LORS_LIBXND_DIR="$with_libexnode",
            LORS_LIBXND_DIR="${INS_DIR}")
AC_FIND_FILE("${LORS_LIBXND_DIR}/lib/libexnode.a",
            LORS_BUILD_LIBXND="no",
            AC_FIND_FILE("${PREFIX}/libexnode/src/exnode.c",
                        LORS_BUILD_LIBXND="yes"
                        LORS_LIBXND_DIR="${INS_DIR}"
                        LORS_LIBXND_SRC_DIR="${PREFIX}/libexnode",
                        AC_MSG_ERROR("Can not find libexnode package")))
AC_SUBST(LORS_BUILD_LIBXND)
AC_SUBST(LORS_LIBXND_SRC_DIR)
AC_SUBST(LORS_LIBXND_DIR)

dnl check for libaes
AC_FIND_FILE("${INS_DIR}/lib/libaes.a",
            LORS_BUILD_LIBAES="no"
						LORS_LIBAES_DIR="${INS_DIR}",
            AC_FIND_FILE("${PREFIX}/libe2e/aes/aes.h",
                        LORS_BUILD_LIBAES="yes"
                        LORS_LIBAES_DIR="${INS_DIR}"
                        LORS_LIBAES_SRC_DIR="${PREFIX}/libe2e/aes",
                        AC_MSG_ERROR("Can not find libaes package")))
AC_SUBST(LORS_BUILD_LIBAES)
AC_SUBST(LORS_LIBAES_SRC_DIR)
AC_SUBST(LORS_LIBAES_DIR)

dnl AC_ARG_WITH(demo, [--with-demo],
dnl            AC_DEFINE(LORS_DEMO) )

E2EDIR="${PREFIX}/libe2e"
AC_SUBST(E2EDIR)


dnl check doxygen
AC_PATH_PROG(DOXYGEN,doxygen,touch)
AC_SUBST(DOXYGEN)

dnl check wish
AC_PATH_PROG(WISH,wish)
AC_SUBST(WISH)

AC_SUBST(PREFIX)

AC_OUTPUT( Makefile lors_setup.sh pre-install.sh doc/doxygen.cfg \
           doc/Makefile src/Makefile libe2e/Makefile cmdtools/Makefile \
           include/Makefile visual/Makefile visual/command.tcl \
           visual/lat_display.tcl, [/bin/sh pre-install.sh] )
