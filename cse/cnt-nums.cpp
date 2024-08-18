// semenInRussia 2024
// https://cses.fi/problemset/task/2220
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int D = 10, N = 20;
using ll = long long;
ll f[N][D];

// return amount of integers < x
ll before(ll x) {
  if (x <= 1) {
    return x;
  }
  x--;

  vector<int> di;
  ll t = x;
  while (t) {
    di.push_back(t % 10);
    t /= 10;
  }
  reverse(di.begin(), di.end());
  // ---

  int sz = int(di.size());

  for (int i = 0; i < sz; i++) {
    for (int d = 0; d < D; d++) {
      f[i][d] = 0;
    }
  }

  for (int i = 0; i < sz; i++) {
    for (int d = 0; d < D; d++) {
      if (i == 0) {
        f[i][d] = d > 0;
        continue;
      }
      for (int o = 0; o < D; o++) {
        if (o != d) {
          f[i][d] += f[i - 1][o];
        }
      }
    }
  }

  ll ans = 1; // 0
  for (int d = 0; d < D; d++) {
    for (int k = 0; k < sz; k++) {
      ans += f[k][d];
    }
  }

  // decrease for every k:
  // - minus ways when previous are the same digits, the k is
  //   greater, other are any

  for (int k = 0; k < sz; k++) {
    // clear:
    for (int i = 0; i < sz; i++) {
      for (int d = 0; d < D; d++) {
        f[i][d] = 0;
      }
    }

    // fill f[N][D]:
    for (int i = 0; i < sz; i++) {
      if (i < k) { // only di[i]
        int d = di[i];
        if (i == 0) {
          f[i][d] = 1;
          continue;
        }
        for (int o = 0; o < D; o++) {
          if (o != d) {
            f[i][d] += f[i - 1][o];
          }
        }
      }

      if (i == k) { // only greater digits
        if (i == 0) {
          for (int d = di[i] + 1; d < D; d++) {
            f[i][d] = 1;
          }
          continue;
        }
        for (int d = di[i] + 1; d < D; d++) {
          for (int o = 0; o < D; o++) {
            if (o != d) {
              f[i][d] += f[i - 1][o];
            }
          }
        }
      }

      if (i > k) { // any
        if (i == 0) {
          for (int d = 1; d < D; d++) {
            f[i][d] = 1;
          }
          continue;
        }
        for (int d = 0; d < D; d++) {
          for (int o = 0; o < D; o++) {
            if (o != d) {
              f[i][d] += f[i - 1][o];
            }
          }
        }
      }
    }

    // update ans:
    for (int d = 0; d < D; d++) {
      ans -= f[sz - 1][d];
    }
  }

  return ans;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << before(b + 1) - before(a);
}
