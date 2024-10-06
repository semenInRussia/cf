// semenInRussia 2024
// https://codeforces.com/contest/2021/problem/C1
#include <iostream>
#include <set>
using namespace std;

const int N = 2e5;
int a[N], b[N];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  set<int> rest;
  bool ans = 1;
  int cur = 0;
  for (int i = 0; i < m; i++) {
    if (b[i] != a[cur] && !rest.count(b[i])) {
      ans = 0;
      break;
    }
    if (!rest.count(b[i])) {
      rest.insert(a[cur++]);
    }
  }
  cout << (ans ? "ya\n" : "tidak\n");
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
