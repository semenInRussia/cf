// semenInRussia 2024
// https://codeforces.com/contest/2031/problem/D
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 6e5;
int a[N], ans[N];
int pref[N], suf[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = max(pref[i - 1], a[i]);
  }

  suf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = min(suf[i + 1], a[i]);
  }

  ans[n - 1] = pref[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    if (pref[i] > suf[i + 1]) {
      ans[i] = ans[i + 1];
    } else {
      ans[i] = pref[i];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
