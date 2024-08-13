// semenInRussia 2024
// https://cses.fi/problemset/task/1637
#include <iostream>
using namespace std;

const int N = 1e6 + 2, inf = 1e9 + 9;
int f[N];

int main() {
  int n;
  cin >> n;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = +inf;
    int t = i;
    while (t) {
      f[i] = min(f[i], f[i - (t % 10)] + 1);
      t /= 10;
    }
  }
  cout << f[n];
}
