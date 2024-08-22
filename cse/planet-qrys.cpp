// semenInRussia 2024
// https://cses.fi/problemset/task/1750
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 100, K = 30;
int up[N][K], t[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i]--;
  }

  // fill up[N][K]
  for (int i = 0; i < n; i++) {
    up[i][0] = t[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < n; i++) {
      up[i][k] = up[up[i][k - 1]][k - 1];
    }
  }

  for (int j = 0; j < q; j++) {
    int i, cnt;
    cin >> i >> cnt;
    i--;
    int b = 1;
    for (int j = 0; j < 30; j++, b <<= 1) {
      if (cnt & b) {
        i = up[i][j];
      }
    }
    cout << (i + 1) << '\n';
  }
}
