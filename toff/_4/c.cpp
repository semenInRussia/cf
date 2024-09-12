// semenInRussia 2024
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using ll = long long;

struct point {
  ll x, y;
  double len() { return hypot(x, y); }
};

point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }
void operator>>(istream &in, point &pt) { in >> pt.x >> pt.y; }

const int N = 2e5;
bool out[N];
point pt[N];
double a[N], b[N], s[N];

int main() {
  int n, k;
  ll l;
  cin >> n >> l >> k;
  for (int i = 0; i < k; i++) {
    int j;
    cin >> j;
    out[j - 1] = 1;
  }

  for (int i = 0; i < n; i++) {
    cin >> pt[i];
  }

  for (int i = 0; i < n - 1; i++) {
    a[i] = (pt[i] - pt[i + 1]).len();
  }
  a[n - 1] = (pt[0] - pt[n - 1]).len();

  // b[i] - part of perimeter where i'th side is ended
  for (int i = 0; i < n; i++) {
    b[i + 1] = b[i] + a[i];
  }
  double p = b[n];

  // s[i] - amount of exit distance from [0; i) sides
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i];
    if (out[i]) {
      s[i + 1] += a[i];
    }
  }

  if (l >= p) {
    cout << "0";
    return 0;
  }
  if (l == 0) {
    cout << s[n];
    return 0;
  }

  double ans = 0; // closed part length
  for (int i = 0; i < n; i++) {
    double e = b[i] + l;
    if (e >= p) {
      // distance
      double e2 = l - (b[n] - b[i]);
      int j = lower_bound(b, b + n + 1, e2) - b - 1;
      double op = s[n] - s[i] + s[j];
      if (out[j]) {
        op += e2 - b[j];
      }
      ans = max(ans, op);
    } else {
      // first b[i] < e
      int j = lower_bound(b, b + n + 1, e) - b - 1;
      assert(b[j] < e);
      double op = s[j] - s[i];
      if (out[j]) {
        op += e - b[j];
      }
      ans = max(ans, op);
    }
  }

  // cout << s[n] << '\n';
  cout << std::fixed << std::setprecision(8) << (s[n] - ans);
}
