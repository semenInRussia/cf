// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;

const int C = 29, N = 1e5 + 100, mod = 1e9 + 7;
int p[N], h[N];

int main() {
  p[0] = 1;
  for (int i = 1; i < N; i++)
    p[i] = 1ll * p[i - 1] * C % mod;

  string a, b;
  cin >> a >> b;
  for (auto &ch : a)
    ch = ch - 'a' + 1;
  for (auto &ch : b)
    ch = ch - 'a' + 1;

  int n = int(a.size());
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * a[i] * p[i]) % mod;

  int m = int(b.size());
  int bh = 0;
  for (int i = 0; i < m; i++)
    bh = (bh + 1ll * b[i] * p[i]) % mod;
  bh = 1ll * bh * p[n] % mod;

  vector<int> answ;
  for (int i = 0; i + m <= n; i++) {
    // check that a[i; i+m) = b
    int sub = (h[i + m] - h[i] + mod) % mod;
    sub = 1ll * sub * p[n - i] % mod;
    if (sub == bh)
      answ.push_back(i + 1);
  }
  cout << answ.size() << '\n';
  for (int x : answ)
    cout << x << ' ';
}
