// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N];
pair<int, int> p[N];
int n;

bool check(int s) {
  int l = s, r = s;
  int w = 0;
  for (int i = 0; i < n; i++) {
    auto [d, j] = p[i];
    if (j <= r && j >= l) {
      continue;
    }
    int v = (j < l) ? (l - j) : (j - r);
    w += v;
    if (w > d) {
      return false;
    }
    l = min(j, l);
    r = max(j, r);
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    p[i] = {a[i], i};
  }
  sort(p, p + n);

  int ans = 0;
  for (int s = 0; s < n; s++) {
    ans += check(s);
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
