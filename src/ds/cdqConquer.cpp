#include "ds/cdqConquer.h"

#include <algorithm>
#include <functional>

#include "ds/fenwick.hpp"

namespace cuzperf {

std::vector<int> cdq(std::vector<cdqNode>& a, int k) {
  // sort by y
  std::vector<int> ans(a.size());
  std::sort(a.begin(), a.end());
  int last = 0;
  for (int i = 1, na = static_cast<int>(a.size()); i < na; ++i) {
    if (a[i].x != a[i - 1].x || a[i].y != a[i - 1].y || a[i].z != a[i - 1].z) {
      int t = i - last - 1;
      for (int j = last; j < i; ++j) {
        ans[a[j].id] = t;
        a[j].w = 0;
      }
      a[i - 1].w = i - last;
      last = i;
    }
  }
  int t = static_cast<int>(a.size()) - last - 1;
  for (int i = last, na = static_cast<int>(a.size()); i < na; ++i) {
    ans[a[i].id] = t;
    a[i].w = 0;
  }
  a.back().w = static_cast<int>(a.size()) - last;
  Fenwick<int64_t> A(k);
  auto cmpy = [](const cdqNode& lhs, const cdqNode& rhs) { return lhs.y < rhs.y; };
  std::function<void(int, int)> divide = [&](int l, int r) {
    if (r - l <= 1) {
      return;
    }
    int m = (l + r) / 2;
    divide(l, m);
    divide(m, r);
    std::sort(a.begin() + l, a.begin() + m, cmpy);
    std::sort(a.begin() + m, a.begin() + r, cmpy);
    int ed = l;
    for (int i = m; i < r; ++i) {
      while (ed < m && a[ed].y <= a[i].y) {
        A.add(a[ed].z, a[ed].w);
        ++ed;
      }
      ans[a[i].id] += A.sum(a[i].z);
    }
    for (int i = l; i < ed; ++i) {
      A.add(a[i].z, -a[i].w);
    }
  };
  divide(0, a.size());
  return ans;
}
// https://www.luogu.com.cn/problem/P3810

}  // namespace cuzperf
