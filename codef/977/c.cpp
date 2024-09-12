// semenInRussia 2024
#include <iostream>
#include <set>
using namespace std;
using ll = long long;

const int maxn = 3e5;
int a[maxn], b[maxn], d[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> d[i];

  multiset<int> h(d, d + m);
  bool ans = true;
  for (int i = 0; i < n && ans; i++) {
    if (a[i] == b[i])
      continue;
    if (!h.count(a[i]))
      ans = false;
    else
      h.erase(h.find(a[i]));
  }

  int has = false;
  for (int i = 0; i < n; i++)
    if (a[i] == d[m - 1])
      has = true;
  ans &= has;
  cout << (ans ? "YES\n" : "NO\n");
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
