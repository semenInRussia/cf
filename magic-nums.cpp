// semenInRussia 2024
// https://codeforces.com/contest/628/problem/D
#include <iostream>
using namespace std;

const int N = 2003, mod = 1e9 + 7;
int n, m, d;
int pw10[N];
string s;

// g[i][M] - is amount of numbers with size=i and Mod by m=M
int g[N][N];

void inc(string &s) {
  int n = int(s.size());
  int r = 1;
  for (int j = n - 1; j >= 0 && r; j--) {
    s[j] += 1;
    r = s[j] >= 10;
    if (r)
      s[j] = 0;
  }
  if (r)
    s.insert(s.begin(), 1);
}

void dec(string &s) {
  int n = int(s.size());
  int r = 1;
  for (int j = n - 1; j >= 0 && r; j--) {
    int x = s[j];
    x -= 1;
    r = x < 0;
    if (r)
      s[j] = 9;
    else
      s[j] = x;
  }
  if (s[0] == 0)
    s.erase(s.begin());
}

int addmod(int x, int d, int i) { return (x + 1ll * d * pw10[n - i - 1]) % m; }

int memo[N][N][2];

int f(int i, int M, bool small) {
  if (i == n) {
    return M == 0;
  }
  int &ans = memo[i][M][small];
  if (ans != -1)
    return ans;

  if (i % 2) {
    if (small || s[i] <= d) {
      return ans = f(i + 1, addmod(M, d, i), small || (s[i] < d));
    }
    return ans = 0;
  }

  int lim = small ? 10 : s[i];
  ans = 0;
  for (int c = i == 0; c < lim; c++) {
    if (c == d)
      continue;
    ans += f(i + 1, addmod(M, c, i), 1);
    ans %= mod;
  }
  if (!small && s[i] != d) {
    ans += f(i + 1, addmod(M, s[i], i), 0);
    ans %= mod;
  }
  return ans;
}

int before(string &a) {
  if (a.size() == 1) {
    return a[0];
  }

  dec(a);
  s = a;
  n = s.size();

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      for (int s = 0; s < 2; s++) {
        memo[i][j][s] = -1;
      }
    }
  }

  int ans = 0;
  for (int c = 1; c <= s[0]; c++) {
    if (c == d)
      continue;
    ans += f(1, addmod(0, c, 0), 1);
    ans %= mod;
  }

  if (s[0] != d) {
    ans += f(1, addmod(0, s[0], 0), 0);
    ans %= mod;
  }
  // cout << n << '\n';

  // other sizes
  for (int sz = 1; sz < n; sz++) {
    ans += g[sz][0] - 1;
    ans %= mod;
  }

  return ans;
}

int main() {
  cin >> m >> d;
  string a, b;
  cin >> a >> b;
  n = int(max(a.size(), b.size()));
  for (auto &ch : a) {
    ch -= '0';
  }
  for (auto &ch : b) {
    ch -= '0';
  }
  pw10[0] = 1;
  for (int i = 1; i <= N; i++) {
    pw10[i] = (1ll * pw10[i - 1] * 10) % m;
  }

  g[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < m; x++) {
      if (i % 2 == 0) {
        int y = addmod(x, d, i);
        g[i][y] += g[i - 1][x];
        g[i][y] %= mod;
        continue;
      }
      for (int c = i == 0; c < 10; c++) {
        if (c == d)
          continue;
        int y = addmod(x, c, i);
        g[i][y] += g[i - 1][x];
        g[i][y] %= mod;
      }
    }
  }

  inc(b);
  int op1 = before(a);
  int op2 = before(b);

  cout << (op2 - op1 + mod) % mod << '\n';
}
