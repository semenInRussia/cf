// semenInRussia 2024
// https://codeforces.com/problemset/problem/1979/D
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6;
int h[maxn], r[maxn], p[maxn];
const int mod = 1e9 + 7, C = 5; // 5 is prime and bigger than 0 and 1

struct hstring {
  int hsh, len, p1;

  bool operator==(hstring other) {
    normalize(other);
    return other.hsh == hsh;
  }

  void normalize(hstring &other) {
    int P = max(other.p1, p1);

    hsh = (1ll * hsh * p[P - p1]) % mod;
    p1 = P;

    other.hsh = (1ll * other.hsh * p[P - other.p1]) % mod;
    other.p1 = P;
  }

  void chop_prefix(hstring pref) {
    assert(pref.len <= len);
    normalize(pref);
    hsh = (hsh - pref.hsh + mod) % mod;
    len -= pref.len;
    p1 += pref.len;
  }

  void add_suffix(hstring suf) {
    normalize(suf);
    suf.hsh = (1ll * suf.hsh * p[len]) % mod;
    hsh = (hsh + suf.hsh) % mod;
    len += suf.len;
  }
};

void numberize_str(string &s) {
  for (auto &ch : s)
    ch = ch - '0' + 1;
}

hstring hsh(string &s) {
  numberize_str(s);
  int n = int(s.size()), h = 0;
  for (int i = 0; i < n; i++)
    h = (h + 1ll * s[i] * p[i]) % mod;
  return {h, (int)s.size(), 0};
}

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  numberize_str(s);
  h[0] = r[0] = 0;
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * s[i] * p[i]) % mod;
  for (int i = 0; i < n; i++)
    r[i + 1] = (r[i] + 1ll * s[i] * p[n - i - 1]) % mod;
  vector<hstring> ok_hashes = {};
  {
    string t;
    char ch = '1';
    for (int inv : {0, 1}) {
      while (t.size() < n) {
        ch = ('0' + '1') - ch;
        for (int i = 0; i < k; i++)
          t.push_back(ch);
      }
      ok_hashes.push_back(hsh(t));
      t.clear();
      ch = '0';
    }
  }

  int ans = -1;
  for (int P = 0; P < n; P++) {
    hstring cur = {h[n], n, 0};

    // chop prefix
    hstring pref = {h[P], P, 0};
    cur.chop_prefix(pref);

    // add reversed prefix to the end
    // h_{n-1}, h_{n-2},
    hstring rpref = {r[P], P, n - P};
    cur.add_suffix(rpref);

    // check that cur is OK!
    if (count(ok_hashes.begin(), ok_hashes.end(), cur) > 0)
      ans = P;
  }
  cout << ans << '\n';
}

int main() {
  p[0] = 1;
  for (int i = 0; i + 1 < maxn; i++)
    p[i + 1] = (1ll * p[i] * C) % mod;
  int T;
  cin >> T;
  while (T--)
    solve();
}
