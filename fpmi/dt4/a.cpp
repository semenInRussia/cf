// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <complex>
#include <iostream>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

int n, m;

using T = long long;
using P = complex<T>;

T X1, Y1, X2, Y2;

T dot(P a, P b) { return (a * conj(b)).real(); }
T cross(P a, P b) { return (a * conj(b)).imag(); }

void check(T i, T j) {
  P a = {X1 - i, Y1 - j};
  P b = {X2 - i, Y2 - j};
  P c = {X2 - X1, Y2 - Y1};

  T D = X1 * (Y2 - j) + X2 * (j - Y1) + i * (Y1 - Y2);

  if (D == 0) {
    return;
  }

  if (dot(a, b) < 0 || dot(-a, c) < 0 || dot(-c, -b) < 0) {
    cout << i << " " << j;
    exit(0);
  }
}

void around(T x, T y) {
  for (T i = max<T>(0, x - 12); i < min<T>(n, x + 12); i++) {
    for (T j = max<T>(0, y - 12); j < min<T>(m, y + 12); j++) {
      check(i, j);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> m;
  cin >> X1 >> Y1 >> X2 >> Y2;

  around(X1, Y1);
  around(X2, Y2);

  assert(0 && "unreachable!");
}
