// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 5005, inf = 1e9 + 100;
int a[N], b[N];

int f[N][N];
pair<pair<int, int>, int> p[N][N];
int nxta[N][N], nxtb[N][N];

int nxt1a[N], nxt1b[N];

int main() {
  int k;
  cin >> k;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }

  for (int v = 0; v < k; v++) {
    nxta[v][n] = n;
    int cur = n;
    for (int i = n - 1; i >= 0; i--) {
      nxta[v][i] = cur;
      if (a[i] == v) {
        cur = i;
      }
    }
    nxt1a[v] = cur;

    nxtb[v][m] = m;
    cur = m;
    for (int i = m - 1; i >= 0; i--) {
      nxtb[v][i] = cur;
      if (b[i] == v) {
        cur = i;
      }
    }
    nxt1b[v] = cur;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] = +inf;
    }
  }

  p[0][0] = {{-1, -1}, -1};

  for (int v = 0; v < k; v++) {
    int i = nxt1a[v];
    int j = nxt1b[v];
    f[i][j] = 1;
    p[i][j] = {{-1, -1}, v};
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (f[i][j] == inf) {
        continue;
      }

      for (int v = 0; v < k; v++) {
        int i2 = nxta[v][i];
        int j2 = nxtb[v][j];
        int op = f[i][j] + 1;
        if (op < f[i2][j2]) {
          f[i2][j2] = op;
          p[i2][j2] = {{i, j}, v};
        }
      }
    }
  }

  cout << f[n][m] << "\n";

  vector<int> ans;

  int i = n;
  int j = m;
  while (i != -1) {
    auto c = p[i][j];
    ans.push_back(c.second);
    i = c.first.first;
    j = c.first.second;
  }

  reverse(ans.begin(), ans.end());
  for (int x : ans) {
    cout << (x + 1) << " ";
  }
}
