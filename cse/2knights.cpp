// semenInRussia 2024
// https://cses.fi/problemset/task/1072
#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e4 + 1;
ll a[N];
int main() {
  a[1] = 0;
  a[2] = 0;
  a[3] = 8;
  int n;
  cin >> n;
  for (int m = 4; m <= n; m++) {
    a[m] = a[m - 1];
    // size of field is m x m
    for (int j = 1; j <= m; j++) {
      const int f = j == m ? 1 : 2;
      for (int g : {1, 2}) {
        a[m] += f * int(j + g <= m);
        a[m] -= j + g == m;
        a[m] += f * int(j - g >= 1);
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    cout << ((i * i * (i * i - 1) / 2) - a[i]) << '\n';
  }
}
