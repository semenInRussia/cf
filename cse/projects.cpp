// semenInRussia 2024
// https://cses.fi/problemset/task/1140
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N], b[N], p[N], o[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    o[i] = i;
    cin >> a[i] >> b[i] >> p[i];
  }
  map<int, ll> f;
  f[0] = 0;

  sort(o, o + n, [](int i, int j) { return b[i] < b[j]; });

  for (int i = 0; i < n; i++) {
    int j = o[i];

    // project a[j], b[j]
    ll prv = prev(f.lower_bound(a[j]))->second;
    f[b[j]] = max(f[b[j]], f.rbegin()->second);
    f[b[j]] = max(f[b[j]], prv + p[j]);
  }

  cout << f.rbegin()->second;
}
