// semenInRussia 2025
// https://acm.timus.ru/problem.aspx?space=1&num=1005
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 20;
int w[N], f[1 << N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  // f[b] - sum of rocks that inside bitset b
  f[0] = 0;
  for (int b = 1; b < (1 << n); b++) {
    int j = __lg(b);
    f[b] = f[b ^ (1 << j)] + w[j];
  }

  int ans = f[(1 << n) - 1]; // sum of weights

  for (int b = 0; b < (1 << n); b++) {
    int s = f[b];
    int t = f[b ^ ((1 << n) - 1)];
    ans = min(ans, abs(s - t));
  }

  cout << ans;
}
