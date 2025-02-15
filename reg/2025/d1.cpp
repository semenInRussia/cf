// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

const int N = 203;
const int K = 1e5;
const int mod = 1e9 + 7;
int f[N][K];

int n, k;

pair<int, int> gen(int r, int b) {
  int len = k - 1;

  int s = 0;
  int pos = 0;

  int cnt = 0;

  for (int j = 1; j < k; j++) {
    b >>= 1;
    for (int z = 1; z < len; z++) {
      s ^= (1 << pos) * (b & 1);
      cnt += b & 1;
      b >>= 1;
      pos++;
    }
    s ^= (1 << pos) * (r & 1);
    cnt += r & 1;
    r >>= 1;
    pos++;
    len--;
  }

  return {s, cnt};
}

string disp(int x) {
  string s;
  while (x) {
    s.push_back('0' + (x & 1));
    x >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}

int h[N];

int t[N][N];
int popc[K];

void solve() { //
  cin >> n >> k;

  int kk = max(2, k * (k - 1) / 2);

  f[0][0] = 1;

  for (int i = 0; i < (1 << k); i++) {
    popc[i] = popc[i / 2] + (i & 1);
  }

  map<int, vector<int>> prv, cur;

  prv[0].push_back(0);

  for (int i = 0; i < n; i++) {
    // cout << i << ".\n";
    int s;
    cin >> s;

    for (int b2 = 0; b2 < (1 << k); b2++) {
      for (auto b1 : prv[s - popc[b2]]) {
        auto [b3, c] = gen(b2, b1);
        (f[i + 1][b3] += f[i][b1]) %= mod;
        cur[c].push_back(b3);
      }
    }

    for (auto &[_, row] : cur) {
      sort(row.begin(), row.end());
      row.resize(unique(row.begin(), row.end()) - row.begin());
    }

    swap(cur, prv);
    cur.clear();
  }

  int ans = 0;
  for (int b = 0; b < (1 << kk); b++) {
    (ans += f[n][b]) %= mod;
  }
  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout.tie(nullptr);
  int tt = 1;
  while (tt--) {
    solve();
    cout << "\n";
  }
}
