#ifndef HXX_SB_UTILS
#define HXX_SB_UTILS

#define SB_DO_CONCAT(x, y) a##y
#define SB_CONCAT(x, y) SB_DO_CONCAT(x, y)

#define SB_DO_STR(x) #x
#define SB_STR(x) SB_DO_STR(x)

#endif // HXX_SB_UTILS
