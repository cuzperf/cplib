#pragma once

#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <tuple>

namespace cuzperf {

/**
* @return \f( \lfloor \frac{a}{n} \rfloor \f)
*/
template <typename T>
T floor(T a, T n) {
  if (n < 0) {
    n = -n;
    a = -a;
  }
  return a < 0 ? (a - n + 1) / n : a / n;
}

/**
* @return \f( \lceil \frac{a}{n} \rceil \f)
*/
template <typename T>
T ceil(T a, T n) {
  if (n < 0) {
    n = -n;
    a = -a;
  }
  return a < 0 ? a / n : (a + n - 1) / n;
}

/**
* @note never mixed it with cin and cout, useful for int128
*/
template <typename T>
class FastIntIO {
 public:
  static T read() {
    T x = 0;
    bool negative = false;
    // you may use buffer instead for speed
    char ch = getchar();
    while (ch < '0' || ch > '9') {
      if (ch == '-') {
        negative = true;
      }
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + ch - '0';
      ch = getchar();
    }
    return negative ? -x : x;
  }
  static void print(T x) {
    if (x < 0) {
      putchar('-');
      x = -x;
    }
    printCore(x);
  }

 private:
  static void printCore(T x) {
    if (x > 9) {
      printCore(x / 10);
    }
    putchar(x % 10 + '0');
  }
};


namespace {
template <typename T>
std::tuple<T, T, T> exGcd_(T a, T b) {
  if (b == 0) {
    return {a, 1, 0};
  }
  auto [d, y, x] = exGcd_(b, a % b);
  return {d, x, y - a / b * x};
}
}  // namespace

/**
* @return [d, x, y] such that \f( d = ax + by = \gcd(a, b) \f) with \f( |x| <= |b|, |y| <= |a| \f)
*/
template <typename T>
std::tuple<T, T, T> exGcd(T a, T b) {
  auto [d, x, y] = exGcd_(std::abs(a), std::abs(b));
  if (a < 0) {
    x = -x;
  }
  if (b < 0) {
    y = -y;
  }
  return {d, x, y};
}

}  // namespace cuzperf
