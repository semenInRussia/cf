// semenInRussia 2024
// https://cses.fi/problemset/task/1690
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 20, mod = 1e9 + 7;
vector<int> g[N], t[N];
int d[N][1 << N];

int f(int x, int b) {
  int &ans = d[x][b];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int y : t[x]) {
    if (((b >> y) & 1) && (x != y)) {
      ans += f(y, b ^ (1 << y));
      ans -= mod * (ans >= mod);
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    t[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    for (int b = 0; b < (1 << n); b++) {
      d[i][b] = -1;
    }
  }
  d[0][0] = 1;
  int b = (1 << n) - 1; // 111
  b ^= (1 << (n - 1));  // 011
  int ans = f(n - 1, b);
  cout << ans;
}
