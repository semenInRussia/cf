// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 1000, inf = 1e9 + 5;
string t[N], answ[N];

int mn; // min i - index of meteorite for given component
bool used[N][N];
int nxt[N][N]; // distance to first earth

int n, m;
void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || t[i][j] != 'M' || used[i][j]) {
    return;
  }
  used[i][j] = 1;
  mn = min(mn, nxt[i][j] - 1);
  for (int z : {-1, +1}) {
    dfs(i + z, j);
    dfs(i, j + z);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  // fill nxt[][]
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      nxt[i][j] = nxt[i + 1][j] + 1;
      if (t[i][j] == '#') {
        nxt[i][j] = 0;
      }
    }
  }

  mn = +inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] == 'M') {
        dfs(i, j);
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    answ[i].resize(m);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // move meteorite to mn cells down
      if (i >= mn && t[i - mn][j] == 'M') {
        answ[i][j] = 'M';
      } else {
        answ[i][j] = t[i][j];
        if (t[i][j] == 'M') {
          answ[i][j] = '.';
        }
      }
    }
  }

  // cout << "mn=" << mn << '\n';
  for (int i = 0; i < n; i++) {
    cout << answ[i] << '\n';
  }
}
