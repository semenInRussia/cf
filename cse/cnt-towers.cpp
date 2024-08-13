// semenInRussia 2024
// https://cses.fi/problemset/task/2413
#include <iostream>
using namespace std;

// f[i][0] - towers where only two separated toys, height=i
// f[i][1] - towers where one toy is the last

const int N = 1e6 + 20, mod = 1e9 + 7;
int f[N][2];

void op(int &x) { x %= mod; }

int main() {
  f[1][0] = f[1][1] = 1;
  for (int i = 2; i < N; i++) {
    f[i][1] = (4ll * f[i - 1][1] + f[i - 1][0]) % mod;
    f[i][0] = (2ll * f[i - 1][0] + f[i - 1][1]) % mod;
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = (f[n][0] + f[n][1]) % mod;
    cout << ans << '\n';
  }
}
