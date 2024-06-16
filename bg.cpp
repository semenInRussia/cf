// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1955/F
#include <iostream>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.all()

ll ans = -1;
void dfs(int a, int b, int c, int d, ll acc = 0) {
  if (a < 0 || b < 0 || c < 0 || d < 0)
    return;
  if (a + b + c + d == 0) {
    ans = max(ans, acc);
    return;
  }

  dfs(a - 1, b, c, d, acc);
  dfs(a, b - 1, c, d, acc);
  dfs(a, b, c - 1, d, acc);
  dfs(a, b, c, d - 1, acc);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ans = -1;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dfs(a, b, c, d);
    cout << ans << '\n';
  }
}
