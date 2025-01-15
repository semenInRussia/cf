// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int K = ('Z' - 'A') + ('z' - 'a') + 10 + 2, L = 10;

const int mod = 998'244'353;

struct mi {
  int v;
  mi(int64_t x = 0) : v(x % mod) { v += mod * (x < 0); }
  explicit operator int() { return v; }
};

mi operator*(mi a, mi b) { return mi(1ll * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }

mi operator+(mi a, mi b) { return mi(1ll * a.v + b.v); }
mi &operator+=(mi &a, mi b) { return a = a + b; }

mi operator-(mi a, mi b) { return mi(a.v - b.v); }
mi &operator-=(mi &a, mi b) { return a = a - b; }
mi pow(mi x, int64_t k) {
  mi ans = 1;
  while (k) {
    if (k & 1) {
      ans *= x;
    }
    k >>= 1;
    x *= x;
  }
  return ans;
}

mi inv(mi x) { return pow(x, mod - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }

istream &operator>>(istream &in, mi &v) { return in >> v.v; }
ostream &operator<<(ostream &out, mi v) { return out << v.v; }

int cnt[K * K];
mi f[K * K * K];

inline int e(char c) {
  if ('A' <= c && c <= 'Z') {
    return c - 'A';
  }
  if ('a' <= c && c <= 'z') {
    return c - 'a' + e('Z') + 1;
  }
  return c - '0' + e('z') + 1;
}

inline int enc(int a, int b) { return a * K + b; }
inline int enc(int a, int b, int c) { return a * K * K + b * K + c; }

vector<string> words[L + 1];

string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}

bool pal(string &w) { return w == rev(w); }

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    words[w.size()].push_back(w);
  }

  for (int i = 0; i <= L; i++) {
    set<pair<int64_t, int64_t>> s;
    auto &row = words[i];

    for (auto &w : row) {
      for (auto &c : w) {
        c = e(c);
      }
      if (rev(w) < w) {
        w = rev(w);
      }
    }

    sort(row.begin(), row.end());
    row.resize(unique(row.begin(), row.end()) - row.begin());
  }

  mi ans = 0;

  int fac[4] = {1, 2, 6, 24};
  int k[16];
  for (int b = 0; b < 8; b++) {
    vector<int> p = {0};
    for (int j = 0; j < 3; j++) {
      if ((b >> j) & 1) {
        p.push_back(0);
      } else {
        p.back()++;
      }
    }

    int ans = 24;

    for (int x : p) {
      ans /= fac[x];
    }

    k[b] = ans;
  }

  for (int l = 1; l <= L; l++) {
    if (words[l].empty()) {
      continue;
    }

    fill(begin(cnt), end(cnt), 0);
    fill(begin(f), end(f), 0);

    for (auto w : words[l]) {
      auto c = enc(w[0], w.back());
      cnt[c] += 1;
      if (!pal(w)) {
        c = enc(w.back(), w[0]);
        cnt[c] += 1;
      }
    }

    // int r = 0;

    for (int b = 0; b < K; b++) {
      for (int c = b; c < K; c++) {
        for (int d = c; d < K; d++) {
          auto &cur = f[enc(b, c, d)];

          for (int a = 0; a < K; a++) {
            auto v = mi(cnt[enc(a, b)]) * cnt[enc(a, c)] * cnt[enc(a, d)];
            cur += v;
          }
        }
      }
    }

    int cur = 0;

    for (int a = 0; a < K; a++) {
      for (int b = a; b < K; b++) {
        cur ^= int(a != b) * (1 << 0);
        for (int c = b; c < K; c++) {
          cur ^= int(b != c) * (1 << 1);
          for (int d = c; d < K; d++) {
            cur ^= int(d != c) * (1 << 2);
            auto v = f[enc(a, c, d)] * f[enc(a, b, d)] * f[enc(a, b, c)] *
                     f[enc(b, c, d)];

            ans += v * k[cur];

            cur ^= int(d != c) * (1 << 2);
          }
          cur ^= int(b != c) * (1 << 1);
        }
        cur ^= int(a != b) * (1 << 0);
      }
    }
  }

  cout << ans << "\n";
}

int main() {
#ifndef home
  cin.tie(nullptr)->sync_with_stdio(0);
#endif

  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  // for (char c = 'A'; c <= 'Z'; c++) {
  //   cout << e(c) << "\n";
  //   assert(e(c) < K);
  // }
  // for (char c = 'a'; c <= 'z'; c++) {
  //   cout << e(c) << "\n";
  //   assert(e(c) < K);
  // }
  // for (char c = '0'; c <= '9'; c++) {
  //   cout << e(c) << "\n";
  //   assert(e(c) < K);
  // }
  // return 0;
  while (tt--) {
    for (int i = 0; i <= L; i++) {
      words[i].clear();
    }
    solve();
  }
}
