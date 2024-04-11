#ifndef HXX_SB_CONFIG_COMPILER_MSVC
#define HXX_SB_CONFIG_COMPILER_MSVC

#include "sb/config/common.hxx"

#if defined(_MSC_FULL_VER)
// MSVC >= Windows Server 2003 SP1 DDK (for AMD64)
#if _MSC_FULL_VER > 100000000
#define SB_MSVC_FULL_VER _MSC_FULL_VER
#else
// MSVC <= Visual C++ .NET 2003 SP1 [7.1]
#define SB_MSVC_FULL_VER (_MSC_FULL_VER * 10)
#endif
#else
// MSVC <= Visual Studio 97 [5.0] Visual C++ 5.0
#define SB_MSVC_FULL_VER (_MSC_VER * 100000)
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Language Feature-Test                            //
////////////////////////////////////////////////////////////////////////////////
// Windows Server 2003 SP1 DDK (for AMD64)
#if !defined(SB_HAS_LONG_LONG) && (_MSC_VER >= 1400 || defined(_MSC_EXTENSIONS))
#define SB_HAS_LONG_LONG
#endif
// Visual Studio 2010 Beta 1 [10.0]
#if !defined(SB_HAS_RVALUE_REFERENCES) && _MSC_VER >= 1600
#define SB_HAS_RVALUE_REFERENCES
#endif
// Visual Studio 2015 [14.0]
#if !defined(SB_HAS_UNICODE_CHARS) && SB_MSVC_FULL_VER >= 190023026
#define SB_HAS_UNICODE_CHARS
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Attribute Feature-Test                           //
////////////////////////////////////////////////////////////////////////////////
#if !defined(SB_ALWAYS_INLINE) && (_MSC_VER >= 1200)
#define SB_ALWAYS_INLINE __forceinline
#endif

#if !defined(SB_ASSUME)
#define SB_ASSUME(x) __assume(x)
#endif

#if !defined(SB_DEPRECATED)
#if(_MSC_VER >= 1400) // Windows Server 2003 SP1 DDK (for AMD64)
#define SB_DEPRECATED_MSG(msg) __declspec(deprecated(msg))
#else
#define SB_DEPRECATED_MSG(msg) __declspec(deprecated)
#endif
#define SB_DEPRECATED __declspec(deprecated)
#endif

#if !defined(SB_NODISCARD)
#define SB_NODISCARD _Check_return_
#define SB_NODISCARD_MSG(msg) _Check_return_
#endif

#if !defined(SB_NOINLINE) && (_MSC_VER >= 1400)
#define SB_NOINLINE __declspec(noinline)
#endif

#if !defined(SB_NORETURN)
#define SB_NORETURN _Noreturn
#endif

////////////////////////////////////////////////////////////////////////////////
//                            Compiler intrinsics                             //
////////////////////////////////////////////////////////////////////////////////
#define SB_HAS_MSVC_INT64

#if SB_MSVC_FULL_VER >= 140050215 // Visual Studio 2005 Beta 2 [8.0]
#define SB_IS_CLASS(x) __is_class(x)
#define SB_IS_ENUM(x) __is_enum(x)
#define SB_IS_UNION(x) __is_union(x)
#endif

#endif // HXX_SB_CONFIG_COMPILER_MSVC
