// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

struct mi {
  int a;
  int64_t b;

  mi() : a(0), b(0) {}
  mi(int x) : a(x), b(x) {}
  mi(int x, int64_t y) : a(x), b(y) {}
};

mi operator-(mi s, mi t) {
  return {
      (s.a - t.a + mod) % mod,
      (s.b - t.b),
  };
}

mi operator+(mi s, mi t) {
  return {
      (s.a + t.a) % mod,
      s.b + t.b,
  };
}

mi operator*(mi s, mi t) {
  return {
      int((1ll * s.a * t.a) % mod),
      s.b * t.b,
  };
}

bool operator<(mi s, mi t) { return s.a < t.a || (s.a == t.a && s.b < t.b); }

const int N = 3e5 + 100;
mi p[N], pref[N];
// pref[i] = hash of 11111 (len=i)

struct stree {
  vector<mi> t;
  vector<int> lazy;
  int sz;

  stree(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1, 0);
    lazy.resize(2 * sz - 1, -1);
  }

  void apply(int x, int v, int l, int r) {
    t[x] = (pref[r] - pref[l]) * v;
    lazy[x] = v;
  }

  void push(int x, int l, int r) {
    if (lazy[x] != -1) {
      int m = (l + r) / 2;
      apply(2 * x + 1, lazy[x], l, m);
      apply(2 * x + 2, lazy[x], m, r);
      lazy[x] = -1;
    }
  }

  void upd(int ql, int qr, int v) { upd(ql, qr, v, 0, 0, sz); }

  mi top() { return t[0]; }

  void upd(int ql, int qr, int v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      apply(x, v, l, r);
      return;
    }

    if (ql >= r || qr <= l) {
      return;
    }

    int m = (l + r) / 2;
    push(x, l, r);
    upd(ql, qr, v, 2 * x + 1, l, m);
    upd(ql, qr, v, 2 * x + 2, m, r);
    t[x] = t[2 * x + 1] + t[2 * x + 2];
  }
};

int len;
string h = " JOI";

string join(string &a, string &b) {
  string ans = "";
  for (int i = 0; i < len; i++) {
    auto ai = a[i];
    auto bi = b[i];
    if (ai == bi) {
      ans += ai;
    } else {
      ans += 6 - bi - ai;
    }
  }
  return ans;
}

int ord(char ch) { return find(h.begin(), h.end(), ch) - h.begin(); }

mi get_hash(string &s) {
  mi ans = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    ans = ans + p[i] * s[i];
  }
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> len;

  string a, b, c;
  cin >> a >> b >> c;

  for (auto &ch : a) {
    ch = ord(ch);
  }
  for (auto &ch : b) {
    ch = ord(ch);
  }
  for (auto &ch : c) {
    ch = ord(ch);
  }

  p[0] = 5;
  for (int i = 1; i <= len + 1; i++) {
    p[i] = p[i - 1] * 5;
  }
  pref[0] = 0;
  for (int i = 0; i <= len + 1; i++) {
    pref[i + 1] = pref[i] + p[i];
  }

  unordered_map<string, int> used;
  used[a] = used[b] = used[c] = true;

  vector<string> v = {a, b, c};

  int cnt = 3; // len of queue (virtual)

  while (cnt > 0) {
    --cnt;
    for (int i = 0; i < (int)v.size(); i++) {
      for (int j = 0; j < (int)v.size(); j++) {
        auto y = join(v[i], v[j]);
        if (!used[y]) {
          used[y] = true;
          ++cnt;
          v.push_back(y);
        }
      }
    }
  }

  vector<mi> h(v.size());
  for (auto &s : v) {
    h.push_back(get_hash(s));
  }

  int q;
  cin >> q;

  string t;
  cin >> t;

  for (auto &c : t) {
    c = ord(c);
  }

  stree st(len);
  for (int i = 0; i < len; i++) {
    st.upd(i, i + 1, t[i]);
  }

  sort(h.begin(), h.end());

  auto repl = [&]() {
    bool ok = binary_search(h.begin(), h.end(), st.top());
    cout << (ok ? "Yes\n" : "No\n");
  };

  repl();

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;

    char ch;
    cin >> ch;

    ch = ord(ch);

    st.upd(l, r, ch);

    repl();
  }
}

// - sort by prefix
// - count elements in interval
