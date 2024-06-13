#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int maxn = 2e5;
int a[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<int, vector<int>> b;
  for (int i = 0; i < n; i++)
    b[a[i] >> 2].push_back(a[i]);
  for (auto &[k, row] : b)
    sort(row.rbegin(), row.rend());
  for (int i = 0; i < n; i++) {
    cout << b[a[i] >> 2].back() << " \n"[i == n - 1];
    b[a[i] >> 2].pop_back();
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
