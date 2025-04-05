// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1000;
int d[N][N];
bool used[N][N];

int main() {
  int k, c, T;
  cin >> k >> c >> T;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      d[i][j] = 2 * T + 3;
    }
  }

  queue<pair<int, int>> q;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x += T + 1;
    y += T + 1;
    q.push({x, y});
    used[x][y] = true;
    d[x][y] = 0;
  }

  for (int i = 0; i < c; i++) {
    int x, y;
    cin >> x >> y;
    x += T + 1;
    y += T + 1;
    used[x][y] = true;
  }

  pair<int, int> ds[4] = {
      {0, +1},
      {+1, 0},
      {-1, 0},
      {0, -1},
  };

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (d[i][j] == T) {
      break;
    }
    for (auto [di, dj] : ds) {
      if (used[i + di][j + dj]) {
        continue;
      }
      used[i + di][j + dj] = true;
      d[i + di][j + dj] = d[i][j] + 1;
      q.push({i + di, j + dj});
    }
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (d[i][j] <= T) {
        ans++;
      }
    }
  }

  cout << ans;
}
