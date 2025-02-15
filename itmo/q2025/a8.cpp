// semenInRussia 2025
#include <bits/stdc++.h>
using namespace std;
const int N = 103;
int n, m, q;
int a[N][N], used1[N][N], used[N][N];

void dfs1(int i, int j, int c) {
  if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] != c || used1[i][j])
    return;

  used1[i][j] = 1;

  dfs1(i + 1, j, c);
  dfs1(i - 1, j, c);
  dfs1(i, j - 1, c);
  dfs1(i, j + 1, c);
}

void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || used[i][j] || used1[i][j])
    return;
  used[i][j] = true;

  dfs(i, j);
  dfs(i, j + 1);
  dfs(i, j - 1);

  dfs(i + 1, j);
  dfs(i + 1, j + 1);
  dfs(i + 1, j - 1);

  dfs(i - 1, j);
  dfs(i - 1, j + 1);
  dfs(i - 1, j - 1);
}

void run() {
  cin >> n >> m >> q;
  n += 3, m += 3;

  int c, i, j;

  while (q--) {
    cin >> c >> i >> j;
    i++, j++;

    for (int i = 0; i < n; i++)
      fill(used[i], used[i] + m, 0), fill(used1[i], used1[i] + m, 0);

    a[i][j] = c;
    dfs1(i, j, c);
    dfs(0, 0);

    int A = 0, B = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] > 0 && !used[i][j])
          a[i][j] = c;
        if (a[i][j] == 1)
          A++;
        if (a[i][j] == 2)
          B++;
      }
    }

    cout << A << ' ' << B << endl;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      a[i][j] = 0;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    run();
  }
}
