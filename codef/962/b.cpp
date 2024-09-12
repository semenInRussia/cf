// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int N = 1000;
string t[N], a[N];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> t[i];
  for (int i = 0; i < (n / k); i++)
    a[i].resize(n / k);
  // 0, k, 2k

  for (int i = 0; i < n; i += k)
    for (int j = 0; j < n; j += k)
      a[i / k][j / k] = t[i][j];
  for (int i = 0; i < (n / k); i++)
    cout << a[i].substr(0, n / k) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
