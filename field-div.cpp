// semenInRussia 2024
// https://codeforces.com/problemset/problem/1980/F1
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 3e6;
using ll = long long;
using pii = pair<int, int>;
pii pt[N]; // (x, y)
int ord[N], a[N];
bool cmp(int i, int j) {
  pii a = pt[i], b = pt[j];
  if (a.first == b.first)
    return a > b;
  return a < b;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    fill(a, a + k, 0);
    for (int i = 0; i < k; i++)
      cin >> pt[i].second >> pt[i].first;
    pt[k++] = {m + 1, -10}; // add fictive (m, 1)
    for (int i = 0; i < k; i++)
      ord[i] = i;
    sort(ord, ord + k, cmp);
    int x = 1, y = 1;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
      int ix = ord[i];
      ll nx = pt[ix].first;
      ans += 1ll * (nx - x) * (n - y + 1);
      int ny = max(y, pt[ix].second + 1);
      if (ny != y)
        y = ny, a[ix] = 1;
      x = nx;
      if (ny > n)
        break;
    }
    k--; // remove fictive
    cout << ans << '\n';
    for (int i = 0; i < k; i++)
      cout << a[i] << ' ';
    cout << '\n';
  }
}
