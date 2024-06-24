// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 1000;
string t[maxn];
vector<int> comp[maxn];
int ncomp = 0, n, m;
int cnt[maxn];

bool areok(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void dfs(int i, int j, int cur) {
  if (!areok(i, j) || t[i][j] == '.' || comp[i][j])
    return;
  comp[i][j] = cur;
  cnt[cur]++;
  for (int d : {-1, +1}) {
    dfs(i + d, j, cur);
    dfs(i, j + d, cur);
  }
}

vector<int> used_comps;
bool used[maxn];
void mbuse(int i, int j, int &cur) {
  if (areok(i, j) && comp[i][j] && !used[comp[i][j]]) {
    cur += cnt[comp[i][j]];
    used_comps.push_back(comp[i][j]);
    used[comp[i][j]] = true;
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> t[i];
  for (int i = 0; i < n; i++) {
    comp[i].resize(m);
    for (auto &x : comp[i])
      x = 0;
  }
  ncomp = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!comp[i][j]) {
        ncomp++;
        cnt[ncomp] = 0;
        dfs(i, j, ncomp);
      }
    }
  }
  int ans = *max_element(cnt + 1, cnt + ncomp + 1);

  // check all rows
  for (int r = 0; r < n; r++) {
    int cur = 0;
    used_comps.clear();
    for (int j = 0; j < m; j++) {
      mbuse(r + 1, j, cur);
      mbuse(r - 1, j, cur);
      if (comp[r][j])
        mbuse(r, j, cur);
      else
        cur++;
    }
    ans = max(ans, cur);
    for (int v : used_comps)
      used[v] = false;
  }
  // all cols
  for (int c = 0; c < m; c++) {
    int cur = 0;
    used_comps.clear();
    for (int i = 0; i < n; i++) {
      mbuse(i, c - 1, cur);
      mbuse(i, c + 1, cur);
      if (comp[i][c])
        mbuse(i, c, cur);
      else
        cur++;
    }
    ans = max(ans, cur);
    for (int v : used_comps)
      used[v] = false;
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
