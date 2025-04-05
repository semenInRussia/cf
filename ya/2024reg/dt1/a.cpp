// semenInRussia 2024
#include <iostream>
#include <numeric>
using namespace std;

using ll = long long;

const int M = 1e6;
int b[M], a[M];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }

  ll ans = 0;

  for (int i = 0; i < m; i++) {
    ans = max(ans, max(ans + 1, 1ll * a[i]) + b[i] - 1);
  }

  cout << ans << "\n";
}
