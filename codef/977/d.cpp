// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

const int maxn = 2e5;
int n;
int a[maxn], b[maxn], t[maxn], bt[maxn];
bool okl[maxn], okr[maxn];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i + 1 < n; i++)
    b[i] = gcd(a[i], a[i + 1]);

  okl[1] = okl[0] = 1;
  for (int i = 2; i < n; i++)
    okl[i] = okl[i - 1] && (b[i - 1] >= b[i - 2]);
  okr[n - 2] = okr[n - 3] = 1;
  for (int i = n - 4; i >= 0; i--)
    okr[i] = okr[i + 1] && (b[i + 1] <= b[i + 2]);

  bool ans = okl[n - 1];
  for (int i = 1; i < n - 1; i++) {
    // try delete i
    int z = gcd(a[i - 1], a[i + 1]);
    if (okl[i - 1] && okr[i + 1] && (i < 2 || z >= b[i - 2]) &&
        (i + 1 >= n - 1 || z <= b[i + 1]))
      ans = 1;
  }
  cout << (ans ? "YES\n" : "NO\n");
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
