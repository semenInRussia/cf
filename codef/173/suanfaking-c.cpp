#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#else
// #pragma GCC optimize("Ofast", "O3")
// #pragma GCC target("avx2")
// #pragma GCC target("abm,bmi,bmi2")//, popvnt
#endif

#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
// #include <cstdio>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;
using namespace std;

//__builtin_clz(m);
using ll = long long;
// using ll = __int128;
using ld = long double;
// using ld = __float128;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vp = vector<pii>;
using vv = vector<vi>;
// mt19937 rnd(20);

template <class T1, class T2>

istream &operator>>(istream &out, pair<T1, T2> &a) {
  cin >> a.first >> a.second;
  return out;
}

template <class T1, class T2>

ostream &operator<<(ostream &out, const pair<T1, T2> &a) {
  cout << a.first << ' ' << a.second;
  return out;
}

template <class T>

ostream &operator<<(ostream &out, const vector<T> &a) {
  for (auto i : a)
    cout << i << ' ';
  cout << '\n';
  return out;
}

template <class T>

istream &operator>>(istream &in, vector<T> &a) {
  for (auto &i : a)
    cin >> i;
  return in;
}

const int maxn = 2e5;
const int lg = 20;
const int inf = 1'000'000'002'500'000'000;

bool find_cycle(int v, vi &used, vv &g, vi &path) {
  used[v] = 1;
  path[v] = 1;
  bool cycl = 0;
  for (int u : g[v]) {
    if (path[u]) {
      cycl = 1;
    }
    if (!used[u])
      cycl |= find_cycle(u, used, g, path);
  }
  path[v] = 0;
  return cycl;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vv a(n, vi(m));
  vv b(n, vi(m));
  cin >> a >> b;
  bool an = 0;
  for (int bit = 0; bit < 31; ++bit) {
    vector<int> to0(n);
    vector<int> to1(m);
    // vv aa = a;
    // vv bb = b;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int aij = (a[i][j] >> bit) & 1;
        int bij = (b[i][j] >> bit) & 1;
        // aa[i][j] = aij;
        // bb[i][j] = bij;
        if (aij == 0 && bij == 1) {
          to1[j] = 1;
        }
      }
      for (int j = 0; j < m; ++j) {
        int aij = (a[i][j] >> bit) & 1;
        int bij = (b[i][j] >> bit) & 1;
        if (to1[j]) {
          aij = 1;
        }
        if (aij == 1 && bij == 0) {
          to0[i] = 1;
        }
      }
    }

    for (int _ = 0; _ < 2; _++) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int aij = (a[i][j] >> bit) & 1;
          int bij = (b[i][j] >> bit) & 1;
          if (to1[j] && to0[i])
            continue;
          if (to1[j]) {
            aij = 1;
          }
          if (to0[i]) {
            aij = 0;
          }
          if (aij == 1 && bij == 0) {
            to0[i] = 1;
          }
          if (aij == 0 && bij == 1) {
            to1[j] = 1;
          }
        }
      }
    }
    vv g(n + m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int aij = a[i][j] >> bit & 1;
        int bij = b[i][j] >> bit & 1;
        if (to1[j] && to0[i]) {
          if (bij == 1) {
            g[i].push_back(j + n);
          } else {
            g[j + n].push_back(i);
          }
        }
      }
    }
    vi used(n + m);
    vi path(n + m);
    for (int i = 0; i < n + m; ++i) {
      if (!used[i]) {
        an |= find_cycle(i, used, g, path);
      }
    }
  }
  if (an) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

signed main() {
  cout << fixed << setprecision(10);
#ifdef MY_FILE
  freopen(R"(C:\Users\Kotle\CLionProjects\untitled\input.txt)", "r", stdin);
  freopen(R"(C:\Users\Kotle\CLionProjects\untitled\output.txt)", "w", stdout);
  int T = time(nullptr);
  int h_ = (T % (3600 * 60) / 3600 + 5) % 24, m_ = T % (3600) / 60, s_ = T % 60;
  auto begin_ = std::chrono::steady_clock::now();
#else
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
#endif
  int t_ = 1;
  cin >> t_;
  while (t_--) {
    solve();
  }
#ifdef MY_FILE
  auto end_ = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end_ - begin_);
  std::cout << "\n==============\nThe time: " << elapsed_ms.count() << " ms\n";
  cout << h_ << ':' << m_ << ':' << s_ << '\n';
#endif
}
