// semenInRussia 2024
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using C = long;
using P = pair<C, C>;

#define X first
#define Y second

inline istream &operator>>(istream &in, P &v) {
  C x, y;
  in >> x >> y;
  v = {x, y};
  return in;
}

inline C dot(const P a, const P b) { return a.X * b.X + a.Y * b.Y; }
inline C cross(const P a, const P b) { return a.X * b.Y - b.X * a.Y; }

const int N = 2e5;
P p[N];

int main() {
  freopen("area.in", "r", stdin);
  freopen("area.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  double ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    ans += cross(p[i], p[i + 1]);
  }
  ans += cross(p[n - 1], p[0]);
  ans = abs(ans) / 2.0;
  cout << ans;
}
