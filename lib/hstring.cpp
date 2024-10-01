// semenInRussia 2024
#include <string>
using namespace std;
#include <algorithm>
#include <cassert>

const int N = 1e6, mod = 1e9 + 7;
int C = 29; // alphabet
int p[N], h[N];

struct hstring {
  int hsh, len, p1;

  hstring(int _hsh, int _len, int _p1) : hsh(_hsh), len(_len), p1(_p1) {}
  hstring(string s) {
    hsh = p1 = 0;
    len = (int)s.size();
    for (auto &ch : s)
      ch = ch - 'a' + 1;
    for (int i = 0; i < len; i++)
      hsh += 1ll * p[i] * s[i] % mod;
  }

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

hstring substr(int h[], int l, int r) { // [l; r)
  hstring a = hstring(h[r], r, 0);
  hstring b = hstring(h[l], l, 0);
  a.chop_prefix(b);
  return a;
}

hstring concat(hstring a, hstring b) {
  a.add_suffix(b);
  return a;
}

int main() {
  // compute p[i] = C^i
  p[0] = 1;
  for (int i = 1; i < N; i++)
    p[i] = (1ll * p[i - 1] * C) % mod;

  // check without substr
  hstring a = string("sem");
  hstring b = string("en");
  hstring c = string("semen");
  assert(!(b == c));
  a.add_suffix(b);
  assert(a == c);
  assert(concat(a, a) == hstring(string("semensemen")));

  // if need in `substr`, compute `h` before
  string s = "abcaabc";
  int n = (int)s.size();
  for (auto &ch : s)
    ch = ch - 'a' + 1;
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * p[i] * s[i] % mod) % mod;

  assert(substr(h, 0, 2) == hstring(string("ab")));
}
