// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int n;

void solve() {
  cin >> n;

  vector<int> a(n), b(n);

  for (int &x : a) {
    cin >> x;
  }

  for (int &x : b) {
    cin >> x;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int u1 = unique(a.begin(), a.end()) - a.begin();
  int u2 = unique(b.begin(), b.end()) - b.begin();

  bool ok = min(u1, u2) >= 2 || max(u1, u2) >= 3;

  cout << (ok ? "YES\n" : "NO\n");
}

int main() {
  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }
}
