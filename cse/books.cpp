// semenInRussia 2024
// https://cses.fi/problemset/task/1158
#include <iostream>
using namespace std;

const int N = 1005, X = 1e5 + 5;
int f[X], c[N], s[N];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  f[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = x; j - c[i] >= 0; j--) {
      f[j] = max(f[j], f[j - c[i]] + s[i]);
    }
  }
  cout << f[x];
}
