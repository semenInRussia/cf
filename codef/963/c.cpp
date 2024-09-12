// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 3e5;
int a[N], val[N];

void solve() {
  int n, k, A = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i], A = max(a[i], A);

  for (int i = 0; i < n; i++) {
    int x = (A - a[i] + k - 1) / k;
    val[i] = x & 1;
    a[i] += x * k - A;
  }

  int L = 0, R = 2 * k;
  // set [0; a[i]) := val[i]
  // set [a[i]; k) := !val[i]
  for (int i = 0; i < n; i++) {
    if (val[i] == 0)
      L = max(L, a[i]);
    else
      R = min(R, a[i]);
  }
  int ans = (R <= L) ? -1 : (L + A);
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
