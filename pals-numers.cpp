// semenInRussia 2024
// https://lightoj.com/problem/palindromic-numbers
// https://vjudge.net/problem/LightOJ-1205
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 30;
ll f[N][2];

void clear(int n) {
  for (int i = 0; i <= n; i++) {
    for (int s : {0, 1}) {
      f[i][s] = 0;
    }
  }
}

ll solve(ll x) {
  if (x == 0)
    return x;
  string s = to_string(x);
  for (auto &ch : s) {
    ch -= '0';
  }
  int n = int(s.size());
  // f[i][s] - ?
  // s:
  // + 0 - small
  // + 1 - big

  clear(n);
  for (int i = 1; i <= n; i++) {
    for (int d = i == 1; d < 10; d++) {
      int nsz = 2 * i;
      // small:
      if (nsz <= n)
        f[i][0] += f[i - 1][0];

      // big:
      if (nsz < n)
        f[i][1] += f[i - 1][1];
    }

    // equal:
    int c = s[i - 1];
    for (int d = i == 1; d < 10; d++) {
      if (d == c)
        continue;
      int s = d > c;
      if (i * 2 < n || (s == 0 && (i * 2) == n))
        f[i][s] += 1;
    }
  }

  ll ans = 1;
  for (int sz = 1; sz <= n; sz++) {
    ans += f[sz][0];
  }
  for (int sz = 1; sz < n; sz++) {
    ans += f[sz][1];
  }
  for (int sz = 1; sz <= n; sz++) {
    if (2 * sz < n) {
      ans++;
    }
    if (2 * sz == n) {
      string d = s.substr(0, sz);
      string str = d;
      reverse(d.begin(), d.end());
      str += d;
      ans += str < s;
    }
  }

  // with odd length
  clear(n);
  for (int i = 1; i <= n; i++) {
    for (int d = i == 1; d < 10; d++) {
      int nsz = (i - 1) * 2 + 1;
      if (nsz <= n)
        f[i][0] += f[i - 1][0];
      if (nsz < n)
        f[i][1] += f[i - 1][1];
    }

    int c = s[i - 1];
    for (int d = i == 1; d < 10; d++) {
      if (d == c)
        continue;
      int s = d > c;
      int nsz = (i - 1) * 2 + 1;
      if (nsz < n || (nsz == n && s == 0))
        f[i][s] += 1;
    }
  }

  for (int sz = 1; sz <= n; sz++) {
    ans += f[sz][0];
  }
  for (int sz = 1; sz < n; sz++) {
    ans += f[sz][1];
  }
  for (int sz = 1; sz <= n; sz++) {
    int nsz = (sz - 1) * 2 + 1;
    if (nsz < n) {
      ans++;
    }
    if (nsz == n) {
      string str = s.substr(0, sz);
      string d = str;
      d.pop_back();
      reverse(d.begin(), d.end());
      str += d;
      ans += str < s;
    }
  }

  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int j = 1; j <= T; j++) {
    cout << "Case " << j << ": ";
    ll a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    ll c = solve(b + 1) - solve(a);
    cout << c << '\n';
  }
}
