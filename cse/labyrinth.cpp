// semenInRussia 2024
// https://cses.fi/problemset/task/1193
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
const int N = 1005, inf = 1e9 + 5;
string t[N];
bool used[N][N];
// dist[i][j] - is minimal distance from i,j to A
int dist[N][N];
// prv[i][j] - is previous cell in that path
pair<int, int> prv[N][N];

bool useless(int i, int j) {
  return i < 0 || i >= n || j < 0 || j >= m || t[i][j] == '#' || used[i][j];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  int ia = -1, ja;
  int ib = -1, jb;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] == 'A') {
        ia = i;
        ja = j;
      }
      if (t[i][j] == 'B') {
        ib = i;
        jb = j;
      }
    }
  }

  // bfs from ia,ij
  queue<pair<int, int>> q;
  q.push({ia, ja});
  dist[ia][ja] = 0;
  used[ia][ja] = 1;
  while (!q.empty()) {
    pair<int, int> x = q.front();
    int i = x.first, j = x.second;
    q.pop();
    pair<int, int> nxt[4] = {
        {i + 1, j},
        {i - 1, j},
        {i, j + 1},
        {i, j - 1},
    };
    for (auto pos : nxt) {
      int ni = pos.first, nj = pos.second;
      if (useless(ni, nj)) {
        continue;
      }
      // cout << "check " << ni << ", " << nj << '\n';
      dist[ni][nj] = dist[i][j] + 1;
      prv[ni][nj] = {i, j};
      used[ni][nj] = 1;
      q.push({ni, nj});
    }
  }

  bool no = !used[ib][jb];
  if (no) {
    cout << "NO";
    return 0;
  }

  // build path
  int i = ib, j = jb;
  string path;
  while (i != ia || j != ja) {
    int prvi = prv[i][j].first, prvj = prv[i][j].second;
    if (j != prvj) {
      path.push_back("LR"[j > prvj]);
    }
    if (i != prvi) {
      path.push_back("DU"[prvi > i]);
    }
    i = prvi, j = prvj;
  }
  reverse(path.begin(), path.end());

  cout << "YES\n";
  cout << dist[ib][jb] << '\n';
  cout << path;
  return 0;
}
