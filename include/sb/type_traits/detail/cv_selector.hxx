#ifndef HXX_SB_TYPE_TRAITS_DETAIL_CV_SELECTOR
#define HXX_SB_TYPE_TRAITS_DETAIL_CV_SELECTOR

namespace sb { namespace detail {
template<typename Unqualified, bool IsConst, bool IsVol> struct cv_selector;
template<typename Unqualified> struct cv_selector<Unqualified, false, false> {
    typedef Unqualified type;
};
template<typename Unqualified> struct cv_selector<Unqualified, false, true> {
    typedef volatile Unqualified type;
};
template<typename Unqualified> struct cv_selector<Unqualified, true, false> {
    typedef const Unqualified type;
};
template<typename Unqualified> struct cv_selector<Unqualified, true, true> {
    typedef const volatile Unqualified type;
};
}} // namespace sb::detail

#endif // HXX_SB_TYPE_TRAITS_DETAIL_CV_SELECTOR
