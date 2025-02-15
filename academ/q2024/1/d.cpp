// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 3e5;
const int inf = 1e9 + 100;
int b[N];

int x[N];
int y[N];

int f[N][2];

int &setmin(int &v, int op) { return v = min(v, op); }

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  sort(b, b + n);

  int k = n / 2;

  for (int i = 0; i < k; i++) {
    x[i] = b[i];
  }
  for (int i = 0; i < k; i++) {
    y[i] = b[i + k];
  }

  swap(x, y);

  int ans = 0;

  x[k] = +inf;
  f[0][0] = 0;
  f[0][1] = 1; // change x[i] = +inf

  for (int i = 0; i < k; i++) {
    f[i + 1][0] = f[i + 1][1] = +inf;

    // only x[i] = +inf (don't touch x[i + 1])
    if (y[i] < x[i + 1]) {
      setmin(f[i + 1][0], f[i][1]);
    }

    // x[i + 1] = +inf (maybe change y[i], maybe change x[i])
    if (y[i] < x[i]) {
      setmin(f[i + 1][1], min(f[i][1], f[i][0]) + 1);
    } else {
      setmin(f[i + 1][1], min(f[i][1], f[i][0] + 1) + 1);
    }

    // change y[i] (if needed)
    setmin(f[i + 1][0], min(f[i][0], f[i][1]) + (y[i] >= x[i]));
  }

  cout << min(f[k][0], f[k][1]);
}
