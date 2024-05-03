#include <bits/types/cookie_io_functions_t.h>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ull = size_t;
using ll = long long;

ull count_balls(ull time, ull t, ull z, ull y) {
  ull cycle = t * z + y;
  ull b = (time / cycle) * z;
  ull rest = time % cycle;

  if (rest >= t * z) {
    b += z;
  } else {
    b += rest / t;
  }

  return b;
}

ull count_balls(ull time, vector<ull> &t, vector<ull> &z, vector<ull> &y) {
  ull balls = 0;

  for (size_t i = 0; i < t.size(); i++) {
    balls += count_balls(time, t[i], z[i], y[i]);
  }

  return balls;
}

int main() {
  ull m, n;
  cin >> m >> n;

  vector<ull> z(n);
  vector<ull> t(n);
  vector<ull> y(n);

  for (size_t i = 0; i < n; i++) {
    cin >> t[i] >> z[i] >> y[i];
  }

  ll l = 0;
  ll r = 1'000'000'000;

  while (r > l + 1) {
    ull time = (r - l) / 2 + l;
    ull b = count_balls(time, t, z, y);

    if (b >= m) {
      r = time;
    } else {
      l = time;
    }
  }

  cout << r << endl;
}
