// semenInRussia 2025
#include <algorithm>
#include <iostream>
using namespace std;

int ans = 0;
int score = 0;
int len = 0;
bool vis = 0;

const int N = 200;
bool used[N][N];
int a[N][N]; // amount of cool points at (i, j)

int n, m, k;

void dfs(int i, int j) {
  if (i == 0 && j == 0 && used[i][j]) {
    ans += (len == 2 * n + 2 * m - 4 && score == k && vis);
    return;
  }

  if (i < 0 || j < 0 || i >= n || j >= m || used[i][j]) {
    return;
  }

  if (i == n - 1 && j == m - 1) {
    vis = true;
  }

  used[i][j] = 1;
  len += 1;
  score += a[i][j];

  for (int di : {-1, +1}) {
    dfs(i + di, j);
    dfs(i, j + di);
  }

  if (i == n - 1 && j == m - 1) {
    vis = false;
  }

  used[i][j] = 0;
  len -= 1;
  score -= a[i][j];
}

int main() {
  cin >> n >> m >> k;
  for (int l = 0; l < k; l++) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    a[i][j]++;
  }

  dfs(0, 0);
  cout << ans;
}
