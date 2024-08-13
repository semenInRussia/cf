// semenInRussia 2024
// https://cses.fi/problemset/task/2168
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5, inf = 1e9 + 100;
struct rang {
  int a, b, i;
};

rang p[N];
int ans1[N], ans2[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].a >> p[i].b;
    p[i].i = i;
  }

  // ans1: find c, d: c >= a, d <= b
  sort(p, p + n,
       [](auto x, auto y) { return x.a < y.a || (x.a == y.a && x.b > y.b); });

  int mn = +inf;
  for (int i = n - 1; i >= 0; i++) {
    ans1[p[i].i] = mn <= p[i].b;
    mn = min(mn, p[i].b);
  }

  // ans2: find c, d: c <= a, d >= b
  sort(p, p + n,
       [](auto x, auto y) { return x.a < y.a || (x.a == y.a && x.b < y.b); });

  int mx = -inf;
  for (int i = 0; i < n; i++) {
    ans2[p[i].i] = mx >= p[i].b;
    mx = max(mx, p[i].b);
  }

  for (int i = 0; i < n; i++)
    cout << ans1[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; i++)
    cout << ans2[i] << ' ';
}
