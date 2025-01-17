// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int inf = 1e9 + 5;

const int N = 500'100;
string s[N];
int nxt[N];

struct dsu {
  vector<int> p, sz;

  dsu(int n) {
    p.resize(n);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      sz[i] = 1;
    }
  }

  void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
  }

  int get(int a) {
    if (p[a] == a) {
      return a;
    }
    p[a] = get(p[a]);
    return p[a];
  }
};

struct SA {
  vector<int> p, c, cn;
  string s;

  SA(string &t) {
    s = t;
    int n = int(s.size());
    p.resize(n);
    c.resize(n);
    cn.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int i, int j) { return s[i] < s[j]; });
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
    }

    vector<vector<int>> b(n + 1);

    for (int len = 1; len < n && c[p[n - 1]] < n - 1; len *= 2) {
      for (int i = 0; i < n; i++) {
        p[i] = (p[i] - len + n) % n;
      }

      // sort p[] by c[]
      for (int i = 0; i < n; i++) {
        b[i].clear();
      }
      for (int i = 0; i < n; i++) {
        b[c[p[i]]].push_back(p[i]);
      }
      int m = 0;
      for (int i = 0; i < n; i++) {
        for (int x : b[i]) {
          p[m++] = x;
        }
      }

      // build c[] again
      cn[p[0]] = 0;
      for (int i = 1; i < n; i++) {
        pii cur = {c[p[i]], c[(p[i] + len) % n]};
        pii prv = {c[p[i - 1]], c[(p[i - 1] + len) % n]};
        cn[p[i]] = cn[p[i - 1]] + (cur != prv);
      }
      swap(c, cn);
    }
  }

  int cmp(int i, string &pat) {
    int j = 0;
    int m = int(pat.size());
    while (j < m && s[i + j] == pat[j]) {
      j++;
    }
    if (j == m) {
      return 0;
    }
    return (s[i + j] < pat[j]) ? -1 : +1;
  };

  // return indexes in suffix array of first and last occurance of w
  pair<int, int> bounds(string &w) {
    int l = -1;
    int r = int(s.size());
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (cmp(p[m], w) < 0) {
        l = m;
      } else {
        r = m;
      }
    }

    if (r >= int(s.size()) || cmp(p[r], w) != 0) {
      return {(int)s.size(), (int)s.size()};
    }

    int L = r;

    l = -1;
    r = (int)s.size();
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (cmp(p[m], w) <= 0) {
        l = m;
      } else {
        r = m;
      }
    }

    int R = l + 1;
    return {L, R};
  }

  // solve problem: count occurance of string (w in t)
  int count(string &w) {
    auto [l, r] = bounds(w);
    return r - l;
  }
};

using pai = uint64_t;

pair<pai, int> f[N];
pai g[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  string t;
  cin >> t;

  int n, k;
  cin >> n >> k;

  dsu ds(n + 30);

  for (int i = 0; i < 26; i++) {
    s[i] = 'a' + i;
  }

  for (int i = 26; i < n + 26; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ds.join(a, b);
  }

  t += '$';
  SA sa(t);

  vector<vector<pair<int, int>>> lef(t.size() + 1), rig(t.size() + 1);

  vector<pair<int, int>> bo(n + 26); // bounds
  for (int j = 0; j < n + 26; j++) {
    auto &w = s[j];
    auto [l, r] = sa.bounds(w);
    int sz = int(w.size());
    lef[l].push_back({sz, j});
    rig[r].push_back({sz, j});
    bo[j] = {l, r};
  }

  set<pair<int, int>> st; // {sz, idx}

  for (int i = 0; i < int(t.size()); i++) {
    for (auto x : lef[i]) {
      st.insert(x);
    }
    for (auto x : rig[i]) {
      auto it = st.find(x);
      if (it != st.end()) {
        st.erase(it);
      }
    }

    if (i > 0) {
      assert(!st.empty());
      nxt[sa.p[i]] = st.rbegin()->second;
    }
  }

  pai C(n + 29);
  if ((n + 29) % 2 == 0) {
    C = pai(n + 30);
  }

  assert(t.back() == '$');
  t.pop_back();

  f[t.size()] = {0, 0};
  for (int i = int(t.size()) - 1; i >= 0; i--) {
    int j = nxt[i];
    pai ch = pai(ds.get(j) + 1);
    int y = i + int(s[j].size());
    f[i] = {f[y].first * C + ch, f[y].second + 1};
  }

  vector<vector<pair<int, int>>> v(t.size() + 1);

  auto encode = [&](int a, int b) {
    uint64_t A = 0;
    for (int i = a; i < b;) {
      auto [sz, j] =
          *prev(upper_bound(v[i].begin(), v[i].end(), make_pair(b - i, +inf)));
      A *= C;
      A += ds.get(j) + 1;
      i += sz;
    }
    return A;
  };

  bool vdone = 0;

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, c--;
    bool bad = b != (int)t.size() || d != int(t.size());

    if (bad && !vdone) {
      vdone = 1;
      for (int i = 0; i < n + 26; i++) {
        auto [l, r] = bo[i];
        int sz = int(s[i].size());
        for (int j = l; j < r; j++) {
          v[sa.p[j]].push_back({sz, i});
        }
      }
      for (int i = 0; i < int(t.size()); i++) {
        sort(v[i].begin(), v[i].end());
      }

      for (int i = 0; i <= int(t.size()); i++) {
        g[i] = encode(0, i);
      }
    }

    bool ok;
    if (a == 0 && c == 0) {
      ok = g[b] == g[d];
    } else if (bad) {
      ok = encode(a, b) == encode(c, d);
    } else {
      ok = f[a] == f[c];
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}
