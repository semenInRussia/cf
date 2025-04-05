// semenInRussia 2025
#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#pragma GCC target("avx2")

using namespace std;

const int N = 1e5;
vector<int> g[N];
bool usd[N];
int s[N];

int solve(int x, int fa = -1) {
  if (usd[x]) {
    return 1;
  }
  vector<int> su;
  for (int y : g[x]) {
    if (y != fa && s[y]) {
      su.push_back(solve(y, x));
    }
  }

  sort(su.begin(), su.end());
  reverse(su.begin(), su.end());
  int ans = 0;
  for (int j = 0; j < int(su.size()); j++) {
    ans = max(ans, su[j] + j);
  }
  return ans;
}

void mark(int x, int fa, int h, int cur) {
  s[x] = usd[x] = cur == h;
  for (int y : g[x]) {
    if (y != fa) {
      mark(y, x, h, cur + 1);
      s[x] += s[y];
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < q; i++) {
    int c, d;
    cin >> c >> d;
    c--;
    mark(c, -1, d, 0);
    cout << solve(c) << "\n";
  }
}
