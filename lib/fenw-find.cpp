// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

// structure that can:
// - add number x (1 <= x <= 1e5)
// - remove number x
// - get k'th number

struct fenw {
  int sz, n;
  vector<int> t;

  fenw(int _n) {
    n = _n;
    sz = 0;
    t.resize(n + 1);
  }

  void add(int i, int v = +1) {
    sz += v;
    i++;
    for (; i < (int)t.size(); i += i & -i) {
      t[i] += v;
    }
  }

  inline void rem(int i) { add(i, -1); }

  // find k: sum(k + 1) == s
  //
  // it last k that sum <s
  int lower_bound(int s) {
    int k = 0;
    for (int l = __lg(n); l >= 0; l--) {
      if (k + (1 << l) <= n && t[k + (1 << l)] < s) {
        k += (1 << l);
        s -= t[k];
      }
    }
    return k;
  }
};
