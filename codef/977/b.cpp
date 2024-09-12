// semenInRussia 2024
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e3;
int a[maxn], ord[maxn];
void solve() {
  auto cmp = greater<int>();
  int n, f, k;
  cin >> n >> f >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int v = a[f - 1];
  sort(a, a + n), reverse(a, a + n);
  int ip = lower_bound(a, a + n, v, cmp) - a;
  int jp = upper_bound(a, a + n, v, cmp) - a - 1;
  if (ip < k && jp < k)
    cout << "YES\n";
  else if (ip < k || jp < k)
    cout << "MAYBE\n";
  else
    cout << "NO\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
