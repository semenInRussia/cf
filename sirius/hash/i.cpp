// semenInRussia 2024
// https://acm.timus.ru/problem.aspx?space=1&num=1486
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;

#pragma GCC optimize("Ofast,unroll-loops")

const int mod = 1e9 + 7;
struct mi {
  int x = 0;
  mi(ll _x = 0) : x(_x % mod) { x += mod * (x < 0); }
  mi operator+(mi o) { return mi(o.x + x); }
  mi operator-(mi o) { return mi(x - o.x); }
  mi operator*(int y) { return mi(1ll * x * y); }
  mi operator*(mi y) { return mi(1ll * x * y.x); }
};
void operator+=(mi &x, mi y) { x = x + y; }

const int N = 508, C = 31;
string t[N];
vector<pii> d[C];
mi a[N][N], b[N][N], p[N], pp[N];
ull ta[N][N], tb[N][N], tp[N], tpp[N];

int n, m;
pair<int, ull> qry(pii pos, int k) {
  auto [i, j] = pos;
  mi h = b[i][j] - b[i][j + k] - b[i + k][j] + b[i + k][j + k];
  ull th = tb[i][j] - tb[i][j + k] - tb[i + k][j] + tb[i + k][j + k];
  return {
      (h * pp[n - i] * p[m - j]).x,
      th * tpp[n - i] * tp[m - j],
  };
}

unordered_map<int, pii> used;
unordered_map<ull, pii> tused;

using answer = pair<int, pair<pii, pii>>;
answer tryc(int c) {
  answer ans = {0, {}};

  int l = -1, r = m + 1;
  while (r - l > 1) {
    used.clear(), tused.clear();
    int k = (r + l) / 2;
    bool ok = 0;
    for (pii p : d[c]) {
      auto [i, j] = p;
      if (i + k > n || j + k > m)
        continue;
      auto h = qry(p, k);
      if (used.count(h.first) && tused.count(h.second) &&
          used[h.first] == tused[h.second]) {
        ok = 1;
        ans = max(ans, {k, {used[h.first], p}});
        break;
      }
      used[h.first] = p;
      tused[h.second] = p;
    }
    if (ok)
      l = k;
    else
      r = k;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> t[i];

  used.rehash((n + 1) * (m + 1));
  tused.rehash((n + 1) * (m + 1));

  tp[0] = 1;
  p[0] = 1;
  for (int i = 1; i <= m; i++)
    p[i] = p[i - 1] * C;
  for (int i = 1; i <= m; i++)
    tp[i] = tp[i - 1] * C;

  mi cc(1);
  ull tcc(1);
  for (int i = 0; i <= m; i++)
    cc += p[i] * ('z' - 'a' + 1);
  for (int i = 0; i <= m; i++)
    tcc += tp[i] * ('z' - 'a' + 1);

  pp[0] = 1;
  tpp[0] = 1;
  for (int i = 1; i <= n; i++)
    pp[i] = pp[i - 1] * cc;
  for (int i = 1; i <= n; i++)
    tpp[i] = tpp[i - 1] * tcc;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v = t[i][j] - 'a' + 1;
      a[i][j] = pp[i] * p[j] * v;
      ta[i][j] = tpp[i] * tp[j] * v;
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      b[i + 1][j + 1] = b[i][j + 1] + b[i + 1][j] - b[i][j] - a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      tb[i + 1][j + 1] = (tb[i][j + 1] + tb[i + 1][j]) - (tb[i][j] + ta[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      d[t[i][j] - 'a'].push_back({i, j});

  answer ans = {0, {}};
  for (int c = 0; c < C; c++)
    ans = max(ans, tryc(c));

  cout << ans.first << '\n';
  if (ans.first)
    for (pii p : {ans.second.first, ans.second.second})
      cout << (p.first + 1) << ' ' << (p.second + 1) << '\n';
}
