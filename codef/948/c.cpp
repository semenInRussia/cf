// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int maxn = 2010;
int a[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
    }
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
