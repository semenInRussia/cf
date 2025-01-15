// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int N = 2e5;

void solve() {
  int n, k;
  cin >> n >> k;

  map<int, int> cnt;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  multiset<int> v;

  for (auto [x, c] : cnt) {
    v.insert(c);
  }

  int ans = (int)v.size();

  for (int x : v) {
    if (x <= k) {
      ans--;
      k -= x;
    }
  }

  cout << max(1, ans) << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
