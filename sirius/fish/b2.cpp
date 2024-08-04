// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast,unroll-loops")

const int M = 2e6;
int z[M];
void concat(string &s, string &t) {
  // t            s
  // please + # + sample
  int n2 = int(s.size()), n1 = int(t.size());
  int m = min(n1, n2);
  int n = m + 1 + m;
  auto get = [n, n2, m, &s, &t](int i) {
    assert(i < n);
    if (i < m)
      return t[i];
    if (i == m)
      return '#';
    i = (i - m - 1 + (n2 - m));
    assert(i < s.size());
    return s[i];
  };

  // for (int i = 0; i < n; i++)
  //   cout << get(i);
  // cout << '\n';

  int l = 0, r = 1;
  z[0] = 0;
  for (int i = 1; i < n; i++) {
    z[i] = 0;
    if (i >= l && i < r)
      z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && get(z[i]) == get(i + z[i]))
      z[i]++;
    if (i + z[i] > r)
      r = i + z[i], l = i;
  }

  int p = 0; // length common suffix/prefix
  for (int i = 0; i < n; i++) {
    if (z[i] == n - i) {
      p = n - i;
      break;
    }
  }

  for (int i = 0; i < p; i++)
    s.pop_back();
  s += t;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout.tie(nullptr);

  int n;
  string s, t;
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    cin >> t;
    concat(s, t);
  }
  cout << s;
}
