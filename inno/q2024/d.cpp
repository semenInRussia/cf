// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

const int N = 3e5;
const int B = (1 << 30) - 1;
int a[N], b[N];

int bit(int x, int j) { return (x >> j) & 1; }

using ope = vector<int>;

const int NOTHING = 0, d0 = 1, d1 = 2, tog = 3;

vector<int> build(ope &op) {
  int k = B; // where zeroes
  int l = 0; // where ones
  int m = 0; // where toggle
  for (int i = 0; i < 30; i++) {
    if (op[i] == d0) {
      k ^= 1 << i;
    } else if (op[i] == d1) {
      l ^= 1 << i;
    } else if (op[i] == tog) {
      m ^= 1 << i;
    }
  }

  return {k, l, m};
}

inline int apply(vector<int> &d, int x) { return ((x & d[0]) | d[1]) ^ d[2]; }

// int apply(ope &op, int x) {
//   int ans = 0;
//   for (int j = 0; j < 30; j++) {
//     if (op[j] == NOTHING) {
//       ans ^= (1 << j) * bit(x, j);
//     } else if (op[j] == d1) {
//       ans ^= 1 << j;
//     } else if (op[j] == tog) {
//       ans ^= (1 << j) * (bit(x, j) ^ 1);
//     }
//   }
//   return ans;
// }

const int c = (1 << 15);

vector<int> _b[c];
int v[N];

void radix_sort(int a[N], int n, vector<int> &d) {
  int A = 0;
  for (int i = 0; i < c; i++) {
    A = max(A, a[i]);
  }

  for (int i = 0; i < n; i++) {
    v[i] = apply(d, a[i]);
  }

  for (int i = 0; i < n; i++) {
    _b[v[i] % c].push_back(a[i]);
  }

  int k = 0;
  for (int i = 0; i < c; i++) {
    for (int x : _b[i]) {
      a[k++] = x;
    }
    _b[i].clear();
  }

  if (A < c) {
    return;
  }

  for (int i = 0; i < n; i++) {
    _b[v[i] / c].push_back(a[i]);
  }

  k = 0;
  for (int i = 0; i < c; i++) {
    for (int x : _b[i]) {
      a[k++] = x;
    }
    _b[i].clear();
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int q;
  cin >> q;

  ope op(30, NOTHING);

  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }

  int A = *max_element(a, a + n);

  auto d = build(op);
  sort(b, b + n);

  bool ch = false;

  for (int i = 0; i < q; i++) {
    int t, x;
    cin >> t >> x;

    if (t == 1) {
      for (int j = 0; j < 30; j++) {
        if (bit(x, j) == 0) {
          ch |= op[j] == tog || op[j] == NOTHING;
          op[j] = d0;
        }
      }
    }

    if (t == 2) {
      for (int j = 0; j < 30; j++) {
        if (bit(x, j) == 1) {
          ch |= op[j] == tog || op[j] == NOTHING;
          op[j] = d1;
        }
      }
    }

    if (t == 3) {
      for (int j = 0; j < 30; j++) {
        if (bit(x, j) == 0) {
          continue;
        }

        if (op[j] == d1) {
          op[j] = d0;
        } else if (op[j] == d0) {
          op[j] = d1;
        } else if (op[j] == tog) {
          ch = true;
          op[j] = NOTHING;
        } else {
          ch = true;
          op[j] = tog;
        }
      }
    }

    if (t == 4) {
      auto d = build(op);
      cout << apply(d, a[x - 1]) << "\n";
    }

    if (t == 5) {
      auto d = build(op);
      if (ch) {
        sort(b, b + n,
             [&d](auto x, auto y) { return apply(d, x) < apply(d, y); });
        ch = false;
      }
      cout << apply(d, b[x - 1]) << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
