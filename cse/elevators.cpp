// semenInRussia 2024
// https://cses.fi/problemset/task/1653
#include <iostream>
using namespace std;

const int N = 20;
int a[N];
pair<int, int> f[1 << N];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  f[0] = {1, 0};
  for (int s = 1; s < (1 << n); s++) {
    f[s] = {n + 1, 0}; // +inf
    for (int j = 0; j < n; j++) {
      if (s & (1 << j)) {
        pair<int, int> op = f[s ^ (1 << j)];
        if (a[j] + op.second > x) {
          op.first++;
          op.second = min(a[j], op.second);
        } else {
          op.second += a[j];
        }
        f[s] = min(f[s], op);
      }
    }
  }
  cout << f[(1 << n) - 1].first;
}
