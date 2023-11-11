#pragma once

#include <stdint.h>

#include <tuple>

namespace cuzperf {

/**
 *  @return \f( x^n \bmod M \f) in \f( O(\log n) \f)
 *  @param \f( n \geq 0,\quad M \geq 0 \f)
 */
int powMod(int x, int n, int M);

/**
 * @return x such that \f( 1 \equiv ax \bmod n \f)
 * @param  \f( \gcd(a, n) = 1 \f)
 * @note \f( (n - n % a) = (n / a) * a  ==>  a^{-1} = -(n / a) (n % a)^{-1} \f)
 */
int inv(int a, int n);

/**
 * @return \f( \gcd(a, b) \f)
 * @note using bit facility
 */
int64_t gcdBit(int64_t a, int64_t b);

/**
 * @return [a, m] such that \f( x = ai \bmod mi, m_i > 0 \equiv x = a \bmod m \f)
 * @note This is called "Chinese remainder theorem"
 */
std::pair<int64_t, int64_t> crt(int a1, int m1, int a2, int m2);

}  // namespace cuzperf
