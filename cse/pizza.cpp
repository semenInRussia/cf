// semenInRussia 2024
// https://cses.fi/problemset/task/1684
// 2sat
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int N = 2e5;
int comp[N];
vector<int> g[N], t[N];

int tim = 0;
int o[N];
bool used[N];

void dfs(int x) {
  used[x] = 1;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y);
    }
  }
  o[tim++] = x;
}

void dfs2(int x, int num) {
  comp[x] = num;
  for (int y : t[x]) {
    if (!comp[y]) {
      dfs2(y, num);
    }
  }
}

int n, m;
inline int notx(int x) {
  if (x < m)
    x += m;
  else
    x -= m;
  return x;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    char ap, bp;
    cin >> ap >> a >> bp >> b;
    a--, b--;

    if (ap == '-') {
      a = notx(a);
    }
    if (bp == '-') {
      b = notx(b);
    }

    // we have condition a || b
    // : !a => b
    // : !b => a
    g[notx(a)].push_back(b);
    g[notx(b)].push_back(a);
  }

  // build t[] - inverted g[]
  for (int x = 0; x < 2 * m; x++) {
    for (int y : g[x]) {
      t[y].push_back(x);
    }
  }

  // top sort
  for (int x = 0; x < 2 * m; x++) {
    if (!used[x]) {
      dfs(x);
    }
  }
  reverse(o, o + (2 * m));

  // compute their component, comp
  int num = 0;
  for (int i = 0; i < 2 * m; i++) {
    int x = o[i];
    if (!comp[x]) {
      dfs2(x, ++num);
    }
  }

  // for every x < m, check that not(a) and a located in different components
  bool ok = 1;
  for (int x = 0; x < m && ok; x++) {
    if (comp[x] == comp[notx(x)]) {
      ok = 0;
    }
  }
  if (!ok) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  // answer (- + -)
  for (int x = 0; x < m; x++) {
    int a = comp[x] > comp[notx(x)];
    cout << "-+"[a] << ' ';
  }
}
