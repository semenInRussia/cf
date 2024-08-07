// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 2e5, C = 31, mod = 1e9 + 7;
int p[N], h1[N], h2[N];
ull tp[N], th1[N], th2[N];

int main() {
  int n;
  cin >> n;
  tp[0] = p[0] = 1;
  for (int i = 1; i <= n + 1; i++)
    p[i] = (1ll * p[i - 1] * C) % mod;
  for (int i = 1; i <= n + 1; i++)
    tp[i] = tp[i - 1] * C;

  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    a[i] = a[i] - 'A' + 1;
    b[i] = b[i] - 'A' + 1;

    h1[i + 1] = (h1[i] + 1ll * p[i] * a[i]) % mod;
    h2[i + 1] = (h2[i] + 1ll * p[i] * b[i]) % mod;

    th1[i + 1] = th1[i] + tp[i] * a[i];
    th2[i + 1] = th2[i] + tp[i] * b[i];
  }

  int l = -1, r = n + 1;
  pii ans = {-1, -1}; // { size, index }

  vector<pair<int, ull>> subs;
  while (r - l > 1) {
    int k = (r + l) / 2;
    int ok = false;

    subs.clear();
    for (int i = 0; i + k <= n; i++) {
      int s1 = 1ll * (h1[i + k] - h1[i] + mod) * p[n - i] % mod;
      ull s2 = (th1[i + k] - th1[i]) * tp[n - i];
      subs.push_back({s1, s2});
    }

    sort(subs.begin(), subs.end());
    for (int i = 0; i + k <= n; i++) {
      int s1 = 1ll * (h2[i + k] - h2[i] + mod) * p[n - i] % mod;
      ull s2 = (th2[i + k] - th2[i]) * tp[n - i];
      pair<int, ull> s = {s1, s2};
      if (binary_search(subs.begin(), subs.end(), s)) {
        ans = max(ans, {k, i});
        ok = true;
        break;
      }
    }
    if (ok)
      l = k;
    else
      r = k;
  }
  for (auto &ch : b)
    ch += 'A' - 1;
  cout << b.substr(ans.second, ans.first) << '\n';
}
