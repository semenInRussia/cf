// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 4005;
const int inf = 1e9 + 5;
int deg[N];
bool G[N][N];

int sz[N]; // size of connectivity component
int h[N], d[N];
int c[N];
bool cut[N];

int ans[N];

int n;

void dfs(int x, int col, int fa = -1) {
  d[x] = h[x] = fa == -1 ? 0 : h[fa] + 1;
  c[x] = col;
  sz[col]++;
  cut[x] = false;

  for (int y = 0; y < n; y++) {
    if (y == fa || !G[x][y]) {
      continue;
    }
    if (c[y] == 0) { // !used, straight edge
      dfs(y, col, x);
      d[x] = min(d[y], d[x]);
      if (d[y] >= h[x] && fa != -1) {
        cut[x] = true;
      }
    } else {
      d[x] = min(h[y], d[x]);
    }
  }

  if (fa == -1 && deg[x] >= 2) {
    cut[x] = true;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;

  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      deg[i] = c[i] = 0;
      for (int j = 0; j < n; j++) {
        G[i][j] = s[j] == '1';
        deg[i] += G[i][j];
      }
    }

    int num = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] == 0) {
        num++;
        sz[num] = 0;
        dfs(i, num);
      }
    }

    int k = 0;       // the answer (amount of nodes)
    bool ok = false; // have answer?

    if (num == 1) {
      ok = true;
      k = 0;
    }

    for (int i = 0; i < n && !ok; i++) {
      if ((!cut[i] && deg[i] + 1 != sz[c[i]]) || sz[c[i]] == 1) {
        ok = true;
        k = 1;
        ans[0] = i + 1;
      }
    }

    if (!ok) {
      // find component with minimum weight
      pair<int, int> bst = {+inf, -1};

      for (int i = 0; i < n; i++) {
        bst = min(bst, {sz[c[i]], c[i]});
      }

      k = 0;
      for (int i = 0; i < n; i++) {
        if (c[i] == bst.second) {
          ans[k++] = i + 1;
        }
      }
    }

    if (num > 2 && k > 2) {
      k = 2;
      ans[0] = 1;

      for (int x = 1; x < n; x++) {
        if (c[x] != c[0]) {
          ans[1] = x + 1;
          break;
        }
      }
    }

    cout << k << "\n";
    if (k != 0) {
      for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
}
