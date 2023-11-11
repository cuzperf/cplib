#ifndef BASE_BUILTIN_H
#define BASE_BUILTIN_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @return \f( a + b \bmod m \f)
 * @par \f( a, b < m \f)
 */
// return (a + b) % m, assume a, b < m
uint64_t addMod(uint64_t a, uint64_t b, uint64_t m);

/**
 * @return \f( a b \bmod m \f)
 */
int64_t mulModi(int64_t a, int64_t b, int64_t m);
/**
 * @return \f( a b \bmod m \f)
 */
uint64_t mulModu(uint64_t a, uint64_t b, uint64_t m);

/**
 * @return \f( \lfloor log_2(x) \rfloor \f)
 * @note base on IEE754 for float: 1 + 8 + 23
 */
int IEE754_lg2_u32(unsigned x);
/**
 * @return \f( \lfloor log_2(x) \rfloor \f)
 * @note base on base on IEE754 for double: 1 + 11 + 52
 */
int IEE754_lg2_u64(uint64_t x);

/**
 * @return \f( \lfloor log_2(x) \rfloor \f)
 * @note UB for x = 0
 */
int lg2_u32(unsigned x);
/**
 * @return \f( \lfloor log_2(x) \rfloor \f)
 * @note UB for x = 0
 */
int lg2_u64(uint64_t x);
// http://graphics.stanford.edu/~seander/bithacks.html

/**
 * @return count leading zeros of x
 * @note UB for x = 0
 */
int clz_u32(unsigned x);
/**
 * @return count leading zeros of x
 * @note UB for x = 0
 */
int clz_u64(uint64_t x);

/**
 * @return count trailing zeros of x
 * @note UB for x = 0
 */
int ctz_u32(unsigned x);
/**
 * @return count trailing zeros of x
 * @note UB for x = 0
 */
int ctz_u64(uint64_t x);
// https://xr1s.me/2018/08/23/gcc-builtin-implementation/

//
/**
 * @return bit count of n
 * @note MIT HAKMEM: about two times faster than __builtin_popcount()
 */
int bitCount_u32(unsigned n);
/**
 * @return bit count of n
 * @note MIT HAKMEM: about two times faster than __builtin_popcountll(), run with 64bit
 */
int bitCount_u64(uint64_t n);
// https://www.cnblogs.com/lukelouhao/archive/2012/06/12/2546267.html

/**
 * @return bit count of n
 * @note using extra int array of len 256
 */
int bitCountTable_u32(unsigned n);
/**
 * @return bit count of n
 * @note using bitCountTable_u32
 */
int bitCountTable_u64(uint64_t n);
// https://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html

// All below are sightly slow than __builtin_parity and __builtin_parityll
bool parity_u32(unsigned n);
// slow than parityMIT_u32
bool parity_u64(uint64_t n);
bool parityTable_u32(unsigned n);  // slow than __builtin_parity
bool parityTable_u64(uint64_t n);  // slow than __builtin_parityll
bool parityMIT_u32(unsigned n);    // slow than parity_u32
bool parityMIT_u64(uint64_t n);

/**
 * @note about 10 times solwer than (unsigned)std::sqrt(double(n)), never use it
 */
unsigned sqrt_u32(unsigned n);
unsigned sqrt_u64(uint64_t n);

// Handbook of Mathematical Functions by M. Abramowitz and I.A. Stegun, Ed.
// Absolute error <= 6.7e-5. Not always faster since std may be computed using hardware
/**
 * @note Handbook of Mathematical Functions by M. Abramowitz and I.A. Stegun, Ed.
 *       Absolute error <= 6.7e-5. Not always faster since std may be computed using hardware
 * @see https://developer.download.nvidia.cn/cg
 */
float acosFast(float x);
float asinFast(float x);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // BASE_BUILTIN_H
