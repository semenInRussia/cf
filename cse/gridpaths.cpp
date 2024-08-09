// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int N = 7;
bool used[N][N];
bool used2[N][N];
// can we reach [n-1; 0]
void dfs(int i, int j) {
  if (i < 0 || j < 0 || i == N || j == N || used2[i][j] || used[i][j])
    return;
  used2[i][j] = 1;
  for (int d : {-1, +1}) {
    dfs(i + d, j);
    dfs(i, j + d);
  }
}

string path;
ll f(int i, int j, int step) {
  if (i < 0 || j < 0 || i == N || j == N || used[i][j])
    return 0;
  if (i == N - 1 && j == 0) {
    used[i][j] = 1;
    int ans = 1;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (used[i][j] == 0)
          ans = 0;
    used[i][j] = 0;
    return ans;
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      used2[i][j] = 0;
  dfs(i, j);
  bool ok = used2[N - 1][0];
  // cout << "OK: " << ok << '\n';
  if (!ok)
    return 0;

  ll ans = 0;
  used[i][j] = 1;
  if (path[step] != '?') {
    char ch = path[step];
    if (ch == 'L')
      ans = f(i, j - 1, step + 1);
    else if (ch == 'R')
      ans = f(i, j + 1, step + 1);
    else if (ch == 'U')
      ans = f(i - 1, j, step + 1);
    else if (ch == 'D')
      ans = f(i + 1, j, step + 1);
    used[i][j] = 0;
    return ans;
  }
  for (int di : {-1, +1})
    ans += f(i + di, j, step + 1);
  for (int dj : {-1, +1})
    ans += f(i, j + dj, step + 1);
  used[i][j] = 0;
  return ans;
}

int main() {
  cin >> path;
  cout << f(0, 0, 0);
}
