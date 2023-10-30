#include <filesystem>
#include <numeric>

#include "math/math.h"
#include "tests/test_util.h"


namespace fs = std::filesystem;

namespace cuzperf {

constexpr static int M = 998244353;
constexpr static int M7 = 1e9 + 7;
constexpr static int M9 = 1e9 + 9;

TEST(MathTest, floor)
{
  EXPECT_EQ(floor(10, 3), 3);
  EXPECT_EQ(floor(-10, 3), -4);
  EXPECT_EQ(floor(10, -3), -4);
  EXPECT_EQ(floor(-10, -3), 3);

  EXPECT_EQ(floor(7762930039189ll, 526618ll), 14741102ll);
  EXPECT_EQ(floor(-7762930039189ll, 526618ll), -14741103ll);
}

TEST(MathTest, ceil)
{
  EXPECT_EQ(ceil(10, 3), 4);
  EXPECT_EQ(ceil(-10, 3), -3);
  EXPECT_EQ(ceil(10, -3), -3);
  EXPECT_EQ(ceil(-10, -3), 4);

  EXPECT_EQ(ceil(7762930039189ll, 526618ll), 14741103ll);
  EXPECT_EQ(ceil(-7762930039189ll, 526618ll), -14741102ll);
}

TEST(MathTest, FastIntIO)
{
  int64_t x1 = 123456789012345678ll;
  int64_t x2 = -x1;
  FastIntIO<int64_t>::print(x1);
  printf("\n");
  FastIntIO<int64_t>::print(x2);
  printf("\n");
#if defined(__GNUC__) && defined(_LP64)
  __int128 y1 = 123456789012345678ll;
  y1 = y1 * 100'000'000'000'000'00ll + 9012345678901234ll;
  __int128 y2 = -y1;
  FastIntIO<__int128>::print(y1);
  printf("\n");
  FastIntIO<__int128>::print(y2);
  printf("\n");
#endif
  fflush(stdout);

  fs::path testsPath = fs::path(__FILE__).parent_path().parent_path().parent_path();
  std::string filename = testsPath.generic_string() + "/test_data/FastIntIO.txt";
  printf("[filename]: %s\n", filename.c_str());
  FILE* file = freopen(filename.c_str(), "r", stdin);
  EXPECT_NE(file, nullptr);

  auto x3 = FastIntIO<int64_t>::read();
  auto x4 = FastIntIO<int64_t>::read();
  EXPECT_EQ(x1, x3);
  EXPECT_EQ(x2, x4);

#if defined(__GNUC__) && defined(_LP64)
  auto y3 = FastIntIO<__int128>::read();
  auto y4 = FastIntIO<__int128>::read();
  EXPECT_EQ(y1, y3);
  EXPECT_EQ(y2, y4);
#endif
  std::fclose(stdin);
}

TEST(MathTest, powMod)
{
  EXPECT_EQ(powMod(0, 123456, 3), 0);

  for (int i = 0; i < 30; ++i) {
    EXPECT_EQ(powMod(2, i, M), 1 << i);
  }

  // a^{p - 1} mod p = 1
  for (int i = 0; i < RUN_CNT; ++i) {
    EXPECT_EQ(powMod(std::abs(static_cast<int>(rnd() % (M - 1))) + 1, M - 1, M), 1);
  }
}

TEST(MathTest, inv)
{
  EXPECT_EQ(inv(1, 2), 1);
  EXPECT_EQ(inv(2, 3), 2);

  for (int i = 0; i < RUN_CNT; ++i) {
    int x = std::abs(static_cast<int>(rnd() % (M - 1)));
    EXPECT_EQ(inv(x, M), powMod(x, M - 2, M));
  }
}

TEST(MathTest, gcdBit)
{
  EXPECT_EQ(gcdBit(0, 0), 0);
  EXPECT_EQ(gcdBit(0, 3), 3);
  EXPECT_EQ(gcdBit(3, 0), 3);
  EXPECT_EQ(gcdBit(2, 3), 1);
  EXPECT_EQ(gcdBit(6, 8), 2);

  for (int i = 0; i < RUN_CNT; ++i) {
    int64_t x = rnd64(), y = rnd64();
    EXPECT_EQ(gcdBit(x, y), std::gcd(x, y));
  }
}

TEST(MathTest, exGcd)
{
  {
    int a = -2, b = 3;
    auto [d, x, y] = exGcd(a, b);
    EXPECT_EQ(d, 1);
    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 1);
  }
  {
    int a = -3, b = 2;
    auto [d, x, y] = exGcd(a, b);
    EXPECT_EQ(d, 1);
    EXPECT_EQ(x, -1);
    EXPECT_EQ(y, -1);
  }

  for (int i = 0; i < RUN_CNT; ++i) {
    int a = rnd(), b = rnd();
    auto [d, x, y] = exGcd(a, b);
    EXPECT_EQ(1LL * a * x + 1LL * b * y, 1LL * d);
  }
#if defined(__GNUC__) && defined(_LP64)
  for (int i = 0; i < RUN_CNT; ++i) {
    int64_t a = rnd64(), b = rnd64();
    auto [d, x, y] = exGcd(a, b);
    EXPECT_EQ(__int128(a) * x + __int128(b) * y, __int128(d));
  }
#endif
}

TEST(MathTest, crt)
{
  {
    auto [x, y] = crt(-1, 3, 2, 6);
    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 6);
  }
  {
    auto [x, y] = crt(1, 3, 1, 7);
    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 21);
  }
  {
    auto [x, y] = crt(2, 6, 6, 14);
    EXPECT_EQ(x, 20);
    EXPECT_EQ(y, 42);
  }

  const auto MM = static_cast<int64_t>(M7) * M9;
  for (int i = 0; i < RUN_CNT; ++i) {
    int64_t xx = rnd64();
    xx = std::abs(xx % M);
    auto [x, y] = crt(xx % M7, M7, xx % M9, M9);
    EXPECT_EQ(xx, x);
    EXPECT_EQ(y, MM);
  }
}

}  // namespace cuzperf
