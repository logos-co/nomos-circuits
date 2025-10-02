// Workaround for a known macOS issue where certain GMP functions fail to compile
// due to strict type checking, despite uint64_t and mp_limb_t being the same size.
// These wrappers explicitly cast uint64_t parameters to mp_limb_t to resolve the mismatch.

#ifndef GMP_PATCH_CAST_HPP
#define GMP_PATCH_CAST_HPP

#include <gmp.h>
#include <cstdint>

// Arithmetic Wrappers
inline mp_limb_t gmp_add_n_cast(uint64_t* rp, const uint64_t* up, const uint64_t* vp, mp_size_t n) {
    return mpn_add_n(reinterpret_cast<mp_limb_t*>(rp),
                     reinterpret_cast<const mp_limb_t*>(up),
                     reinterpret_cast<const mp_limb_t*>(vp),
                     n);
}

inline mp_limb_t gmp_sub_n_cast(uint64_t* rp, const uint64_t* up, const uint64_t* vp, mp_size_t n) {
    return mpn_sub_n(reinterpret_cast<mp_limb_t*>(rp),
                     reinterpret_cast<const mp_limb_t*>(up),
                     reinterpret_cast<const mp_limb_t*>(vp),
                     n);
}

inline mp_limb_t gmp_add_1_cast(uint64_t* rp, const uint64_t* up, mp_size_t n, mp_limb_t b) {
    return mpn_add_1(reinterpret_cast<mp_limb_t*>(rp),
                     reinterpret_cast<const mp_limb_t*>(up),
                     n, b);
}

inline mp_limb_t gmp_sub_1_cast(uint64_t* rp, const uint64_t* up, mp_size_t n, mp_limb_t b) {
    return mpn_sub_1(reinterpret_cast<mp_limb_t*>(rp),
                     reinterpret_cast<const mp_limb_t*>(up),
                     n, b);
}

inline int gmp_cmp_cast(const uint64_t* up, const uint64_t* vp, mp_size_t n) {
    return mpn_cmp(reinterpret_cast<const mp_limb_t*>(up),
                   reinterpret_cast<const mp_limb_t*>(vp),
                   n);
}

inline void gmp_copyi_cast(uint64_t* dst, const uint64_t* src, mp_size_t n) {
    mpn_copyi(reinterpret_cast<mp_limb_t*>(dst),
              reinterpret_cast<const mp_limb_t*>(src),
              n);
}

inline mp_limb_t gmp_mul_1_cast(uint64_t* rp, const uint64_t* up, mp_size_t n, mp_limb_t b) {
    return mpn_mul_1(reinterpret_cast<mp_limb_t*>(rp),
                     reinterpret_cast<const mp_limb_t*>(up),
                     n, b);
}

inline mp_limb_t gmp_addmul_1_cast(uint64_t* rp, const uint64_t* up, mp_size_t n, mp_limb_t b) {
    return mpn_addmul_1(reinterpret_cast<mp_limb_t*>(rp),
                        reinterpret_cast<const mp_limb_t*>(up),
                        n, b);
}

inline mp_limb_t gmp_add_cast(uint64_t* rp, const uint64_t* up, mp_size_t un, const uint64_t* vp, mp_size_t vn) {
    return mpn_add(reinterpret_cast<mp_limb_t*>(rp),
                   reinterpret_cast<const mp_limb_t*>(up), un,
                   reinterpret_cast<const mp_limb_t*>(vp), vn);
}

// Logic/Bitwise Wrappers
inline int gmp_zero_p_cast(const uint64_t* up, mp_size_t n) {
    return mpn_zero_p(reinterpret_cast<const mp_limb_t*>(up), n);
}

inline void gmp_and_n_cast(uint64_t* rp, const uint64_t* up, const uint64_t* vp, mp_size_t n) {
    mpn_and_n(reinterpret_cast<mp_limb_t*>(rp),
              reinterpret_cast<const mp_limb_t*>(up),
              reinterpret_cast<const mp_limb_t*>(vp),
              n);
}

inline void gmp_com_cast(uint64_t* rp, const uint64_t* up, mp_size_t n) {
    mpn_com(reinterpret_cast<mp_limb_t*>(rp),
            reinterpret_cast<const mp_limb_t*>(up),
            n);
}

inline void gmp_ior_n_cast(uint64_t* rp, const uint64_t* up, const uint64_t* vp, mp_size_t n) {
    mpn_ior_n(reinterpret_cast<mp_limb_t*>(rp),
              reinterpret_cast<const mp_limb_t*>(up),
              reinterpret_cast<const mp_limb_t*>(vp),
              n);
}

inline void gmp_xor_n_cast(uint64_t* rp, const uint64_t* up, const uint64_t* vp, mp_size_t n) {
    mpn_xor_n(reinterpret_cast<mp_limb_t*>(rp),
              reinterpret_cast<const mp_limb_t*>(up),
              reinterpret_cast<const mp_limb_t*>(vp),
              n);
}

// Shift Wrappers

inline mp_limb_t gmp_lshift_cast(uint64_t* rp, const uint64_t* up, mp_size_t n, unsigned int cnt) {
    return mpn_lshift(reinterpret_cast<mp_limb_t*>(rp),
                      reinterpret_cast<const mp_limb_t*>(up),
                      n, cnt);
}

inline mp_limb_t gmp_rshift_cast(uint64_t* rp, const uint64_t* up, mp_size_t n, unsigned int cnt) {
    return mpn_rshift(reinterpret_cast<mp_limb_t*>(rp),
                      reinterpret_cast<const mp_limb_t*>(up),
                      n, cnt);
}

// Undefine existing GMP macros
#undef mpn_add_n
#undef mpn_sub_n
#undef mpn_add_1
#undef mpn_sub_1
#undef mpn_cmp
#undef mpn_copyi
#undef mpn_mul_1
#undef mpn_addmul_1
#undef mpn_add
#undef mpn_zero_p
#undef mpn_and_n
#undef mpn_com
#undef mpn_ior_n
#undef mpn_xor_n
#undef mpn_lshift
#undef mpn_rshift

// Redefine GMP macros to wrappers
#define mpn_add_n      gmp_add_n_cast
#define mpn_sub_n      gmp_sub_n_cast
#define mpn_add_1      gmp_add_1_cast
#define mpn_sub_1      gmp_sub_1_cast
#define mpn_cmp        gmp_cmp_cast
#define mpn_copyi      gmp_copyi_cast
#define mpn_mul_1      gmp_mul_1_cast
#define mpn_addmul_1   gmp_addmul_1_cast
#define mpn_add        gmp_add_cast
#define mpn_zero_p     gmp_zero_p_cast
#define mpn_and_n      gmp_and_n_cast
#define mpn_com        gmp_com_cast
#define mpn_ior_n      gmp_ior_n_cast
#define mpn_xor_n      gmp_xor_n_cast
#define mpn_lshift     gmp_lshift_cast
#define mpn_rshift     gmp_rshift_cast

#endif // GMP_PATCH_CAST_HPP
