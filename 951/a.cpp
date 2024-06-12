// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 2e5;
int a[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int mn = INT32_MAX;
  for (int i = 0; i + 1 < n; i++)
    mn = min(mn, max(a[i], a[i + 1]));
  cout << mn - 1 << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
