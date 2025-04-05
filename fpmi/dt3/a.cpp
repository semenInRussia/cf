// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

const int N = 250;
int p[N];
bool cycle[N], used[N];
int k[N], s[N];

vector<int> g[N];

const int inf = 1e18 + 5;

int &setmax(int &v, int p) { return v = max(v, p); }

// sum on subtree
int vk[N], vs[N];
vector<pair<int, int>> buf;

struct knaps {
  vector<int> dp1, dp2;
  int sz;

  knaps(int _sz) : sz(_sz) {
    dp1.resize(sz, -inf);
    dp2.resize(sz, -inf);
  }

  void st(int kk, int ss) {
    if (kk < sz) {
      dp1[kk] = ss;
    }
  }

  int best() { return max(0ll, *max_element(dp1.begin(), dp1.end())); }

  void add(int k, int s) {
    for (int j = sz - 1; j >= k; j--) {
      if (dp1[j - k] != -inf) {
        setmax(dp2[j], dp1[j - k] + s);
      }
    }
  }

  void save() {
    for (int j = 0; j < sz; j++) {
      setmax(dp1[j], dp2[j]);
    }
    fill(dp2.begin(), dp2.end(), -inf);
  }
};

int K;

void merge(knaps &a, knaps &b) {
  int sz = (int)a.dp1.size();
  for (int j = 0; j < sz; j++) {
    if (b.dp1[j] != -inf) {
      a.add(j, b.dp1[j]);
    }
  }
  a.save();
}

knaps dfs(int x) {
  knaps kp(K + 1);
  kp.st(k[x], s[x]);
  for (int y : g[x]) {
    assert(!cycle[y]);
    auto t = dfs(y);
    merge(kp, t);
  }
  return kp;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n >> K;
  buf.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    if (p[i] == -1) {
      p[i] = i;
    }
    g[p[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }

  knaps big(K + 1);
  big.st(0, 0);

  vector<int> path;

  for (int i = 0; i < n; i++) {
    path.clear();
    int x = i;
    while (!used[x]) {
      path.push_back(x);
      used[x] = true;
      x = p[x];
    }

    auto t = find(path.begin(), path.end(), x) - path.begin();
    if (t == (int)path.size()) {
      continue;
    }
    int kk = 0;
    int ss = 0;

    for (int j = t; j < (int)path.size(); j++) {
      int x = path[j];
      cycle[x] = true;
      kk += k[x];
      ss += s[x];
    }

    knaps kp(K + 1);
    kp.st(kk, ss);

    for (int j = t; j < (int)path.size(); j++) {
      int x = path[j];
      for (int y : g[x]) {
        if (!cycle[y]) {
          auto t = dfs(y);
          merge(kp, t);
        }
      }
    }

    for (int j = 0; j <= K; j++) {
      if (kp.dp1[j] != -inf) {
        big.add(j, kp.dp1[j]);
      }
    }
    big.save();
  }

  cout << big.best() << "\n";
}
