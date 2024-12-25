// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <set>

using namespace std;

const int N = 3e5;
int a[N];

pair<int, int> bounds(int l, int r) {
  int mn = 0, mx = 0;
  int pmn = 0, pmx = 0;

  int s = 0;
  for (int i = l; i < r; i++) {
    s += a[i];
    pmn = min(pmn, s);
    pmx = max(pmx, s);
    mn = min(mn, s - pmx);
    mx = max(mx, s - pmn);
  }

  return {mn, mx};
}

set<int> ans;

void push(pair<int, int> lr) {
  auto [l, r] = lr;
  for (int i = l; i <= r; i++) {
    ans.insert(i);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int r = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] != -1 && a[i] != +1) {
      r = i;
    }
  }

  ans.clear();
  push(bounds(0, r));
  push(bounds(r + 1, n));

  int mn = 0, mx = 0;

  int s = 0;
  for (int i = r - 1; i >= 0; i--) {
    s += a[i];
    mn = min(mn, s);
    mx = max(mx, s);
  }

  int L = mn + a[r], R = mx + a[r];

  s = -a[r];
  for (int i = r; i < n; i++) {
    s += a[i];
    L = min(L, s + mn + a[r]);
    R = max(R, s + mx + a[r]);
  }

  push({L, R});
  cout << ans.size() << "\n";
  for (int el : ans) {
    cout << el << " ";
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
