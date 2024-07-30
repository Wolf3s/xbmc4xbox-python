/* Module configuration */

/* This file contains the table of built-in modules.
   See init_builtin() in import.c. */

#include "Python.h"

extern PyObject* PyInit_array(void);
#ifndef MS_WINI64
extern PyObject* PyInit_audioop(void);
#endif
extern PyObject* PyInit_binascii(void);
extern PyObject* PyInit_cmath(void);
extern PyObject* PyInit_errno(void);
extern PyObject* PyInit_gc(void);
extern PyObject* PyInit_math(void);
extern PyObject* PyInit__md5(void);
extern PyObject* PyInit_nt(void);
extern PyObject* PyInit_operator(void);
extern PyObject* PyInit_signal(void);
extern PyObject* PyInit__sha1(void);
extern PyObject* PyInit__sha256(void);
extern PyObject* PyInit__sha512(void);
extern PyObject* PyInit_time(void);
extern PyObject* PyInit__thread(void);
#ifdef WIN32
extern PyObject* PyInit_msvcrt(void);
extern PyObject* PyInit__locale(void);
#endif
extern PyObject* PyInit__codecs(void);
extern PyObject* PyInit__weakref(void);
extern PyObject* PyInit_xxsubtype(void);
extern PyObject* PyInit_zipimport(void);
extern PyObject* PyInit__random(void);
extern PyObject* PyInit_itertools(void);
extern PyObject* PyInit__collections(void);
extern PyObject* PyInit__heapq(void);
extern PyObject* PyInit__bisect(void);
extern PyObject* PyInit__symtable(void);
extern PyObject* PyInit_mmap(void);
extern PyObject* PyInit__csv(void);
extern PyObject* PyInit__sre(void);
extern PyObject* PyInit_parser(void);
extern PyObject* PyInit_winreg(void);
extern PyObject* PyInit__struct(void);
extern PyObject* PyInit__datetime(void);
extern PyObject* PyInit__functools(void);
extern PyObject* PyInit__json(void);
extern PyObject* PyInit_zlib(void);

extern PyObject* PyInit__multibytecodec(void);
extern PyObject* PyInit__codecs_cn(void);
extern PyObject* PyInit__codecs_hk(void);
extern PyObject* PyInit__codecs_iso2022(void);
extern PyObject* PyInit__codecs_jp(void);
extern PyObject* PyInit__codecs_kr(void);
extern PyObject* PyInit__codecs_tw(void);
extern PyObject* PyInit__subprocess(void);
extern PyObject* PyInit__lsprof(void);
extern PyObject* PyInit__ast(void);
extern PyObject* PyInit__io(void);
#ifdef _XBMC /*Activate for XBMC*/
extern PyObject* PyInit__pickle(void);
#endif
extern PyObject* PyInit_atexit(void);
extern PyObject* _PyWarnings_Init(void);
extern PyObject* PyInit__string(void);

/* tools/freeze/makeconfig.py marker for additional "extern" */
/* -- ADDMODULE MARKER 1 -- */

extern PyObject* PyMarshal_Init(void);
extern PyObject* PyInit_imp(void);

struct _inittab _PyImport_Inittab[] = {

    {"array", PyInit_array},
    {"_ast", PyInit__ast},
#ifdef MS_WINDOWS
#ifndef MS_WINI64
#ifndef _XBOX
    {"audioop", PyInit_audioop},
#endif
#endif
#endif
    {"binascii", PyInit_binascii},
    {"cmath", PyInit_cmath},
    {"errno", PyInit_errno},
    {"gc", PyInit_gc},
    {"math", PyInit_math},
    {"nt", PyInit_nt}, /* Use the NT os functions, not posix */
    {"operator", PyInit_operator},
    {"signal", PyInit_signal},
    {"_md5", PyInit__md5},
    {"_sha1", PyInit__sha1},
    {"_sha256", PyInit__sha256},
    {"_sha512", PyInit__sha512},
    {"time", PyInit_time},
#ifdef WITH_THREAD
    {"_thread", PyInit__thread},
#endif
#ifdef WIN32
#ifndef _XBOX
    {"msvcrt", PyInit_msvcrt},
#endif
    {"_locale", PyInit__locale},
#endif
#ifndef _XBOX
    /* XXX Should _subprocess go in a WIN32 block?  not WIN64? */
    {"_subprocess", PyInit__subprocess},
#endif

    {"_codecs", PyInit__codecs},
    {"_weakref", PyInit__weakref},
    {"_random", PyInit__random},
    {"_bisect", PyInit__bisect},
    {"_heapq", PyInit__heapq},
    {"_lsprof", PyInit__lsprof},
    {"itertools", PyInit_itertools},
    {"_collections", PyInit__collections},
    {"_symtable", PyInit__symtable},
#ifndef _XBOX
    {"mmap", PyInit_mmap},
#endif
    {"_csv", PyInit__csv},
    {"_sre", PyInit__sre},
    {"parser", PyInit_parser},
#ifndef _XBOX
    {"winreg", PyInit_winreg},
#endif
    {"_struct", PyInit__struct},
    {"_datetime", PyInit__datetime},
    {"_functools", PyInit__functools},
    {"_json", PyInit__json},

    {"xxsubtype", PyInit_xxsubtype},
    {"zipimport", PyInit_zipimport},
    {"zlib", PyInit_zlib},

    /* CJK codecs */
    {"_multibytecodec", PyInit__multibytecodec},
#ifndef _XBMC
    {"_codecs_cn", PyInit__codecs_cn},
    {"_codecs_hk", PyInit__codecs_hk},
    {"_codecs_iso2022", PyInit__codecs_iso2022},
    {"_codecs_jp", PyInit__codecs_jp},
    {"_codecs_kr", PyInit__codecs_kr},
    {"_codecs_tw", PyInit__codecs_tw},
#endif
/* tools/freeze/makeconfig.py marker for additional "_inittab" entries */
/* -- ADDMODULE MARKER 2 -- */

    /* This module "lives in" with marshal.c */
    {"marshal", PyMarshal_Init},

    /* This lives it with import.c */
    {"imp", PyInit_imp},

    /* These entries are here for sys.builtin_module_names */
    {"__main__", NULL},
    {"builtins", NULL},
    {"sys", NULL},
    {"_warnings", _PyWarnings_Init},
    {"_string", PyInit__string},

    {"_io", PyInit__io},
#ifdef _XBMC /*Activate for XBMC.*/
    {"_pickle", PyInit__pickle},
#endif
	{"atexit", PyInit_atexit},

    /* Sentinel */
    {0, 0}
};
