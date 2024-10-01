// semenInRussia 2024
// https://codeforces.com/problemset/problem/894/E
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int N = 1e6;
vector<pii> g[N], t[N];

int col[N];

// topsort
int ti = 0;
bool used[N];
int o[N];
void topsort(int x) {
  if (used[x]) {
    return;
  }
  used[x] = 1;
  for (auto [y, _w] : g[x]) {
    topsort(y);
  }
  o[ti++] = x;
}

// paint
void paint(int x, int c) {
  if (col[x]) {
    return;
  }
  col[x] = c;
  for (auto [y, w] : t[x]) {
    paint(y, c);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    g[a].push_back({b, w});
    t[b].push_back({a, w});
  }
  for (int x = 0; x < n; x++) {
    topsort(x);
  }
  reverse(o, o + ti);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x = o[i];
    if (col[x] == 0) {
      paint(x, ++cnt);
    }
  }
}
