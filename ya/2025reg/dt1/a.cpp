// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

struct event {
  bool typ;
  int64_t l, r;
};

bool operator<(event a, event b) { return a.l < b.l; }

const int N = 1e5 + 100;
event a[N];
int p[N];
bool bad[N];

void solve() {
  int n;
  int64_t d, t;
  cin >> n >> d >> t;

  for (int i = 0; i < n; i++) {
    cin >> a[i].l >> a[i].r >> a[i].typ;
  }

  a[n] = {1, 0, 0};
  n++;
  a[n] = {0, d, d};

  sort(a, a + n);

  int prv = 0;

  for (int i = 0; i < n; i++) {
    p[i] = prv;
    if (a[i + 1].l - a[i].r >= t) {
      prv = i;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!a[i].typ) {
      bad[p[i]] = true;
    }
  }

  bool hom = true;
  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    int64_t v = a[i + 1].l - a[i].r;

    if (hom) {
      ans += a[i].r - a[i].l;
    }
    if (hom && bad[i]) {
      hom = false;
      ans += v - t;
    } else if (hom) {
      ans += v;
    } else if (!hom && v >= t && !bad[i]) {
      hom = true;
      ans += v - t;
    } else if (!hom && v >= 2 * t && bad[i]) {
      ans += v - 2 * t;
    }
  }

  cout << ans;
  assert(ans >= 0);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    fill(bad, bad + N, false);
    solve();
    cout << "\n";
  }
}
