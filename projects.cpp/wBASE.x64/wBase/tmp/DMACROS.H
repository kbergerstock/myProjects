//dmacros.h
// macros used to build dll's

#if defined (BUILDING__DLL)
   #define _DCLASS _export
#elif defined(USING_DLL)
   #define _DCLASS _import
#else
   #define _DCLASS
#endif