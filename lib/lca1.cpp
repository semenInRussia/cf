// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 100;
pair<int, int> e[N * 2]; // { height, x }
vector<int> g[N];
int tin[N], tout[N];
int h[N];

int ti = 0;

void dfs(int x, int p = -1) {
  h[x] = p == -1 ? 0 : h[p] + 1;
  tin[x] = ti;
  e[ti++] = {h[x], x};
  for (int y : g[x]) {
    if (y != p) {
      dfs(y, x);
      e[ti++] = {h[x], x};
    }
  }
  tout[x] = ti;
}

// build sparse table on e[]
const int L = 19; // ~= log(N)
pair<int, int> st[2 * N][L];

bool p(int x, int y) { // y in x
  return tin[x] <= tin[y] && tin[y] <= tout[x];
}

int lca(int x, int y) {
  if (p(x, y)) {
    return x;
  }
  if (p(y, x)) {
    return y;
  }
  int l = tin[x];
  int r = tin[y];
  if (l > r) {
    swap(l, r);
  }
  int k = __lg(r - l);
  int lc = min(st[l][k], st[r - (1 << k)][k]).second;
  return lc;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int a = 1; a < n; a++) {
    int b;
    cin >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0);

  for (int i = 0; i < ti; i++) {
    st[i][0] = e[i];
  }
  for (int k = 0; k < L; k++) {
    for (int i = 0; i + (2 << k) <= ti; i++) {
      st[i][k + 1] = min(st[i][k], st[i + (1 << k)][k]);
    }
  }

  int a, b;
  cin >> a >> b;
  a--, b--;
  cout << lca(a, b) << "!";
}
