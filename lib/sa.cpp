// suffix array semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int N = 3e5 + 500;

struct SA {
  int p[N], c[N], cn[N];
  string s;

  SA(string &t) {
    s = t;
    s += '$';
    int n = int(s.size());
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
    sort(p, p + n, [&](int i, int j) { return s[i] < s[j]; });
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string t;
  cin >> t;
  SA sa(t);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    cout << sa.count(w) << "\n";
  }
}
