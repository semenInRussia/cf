// semenInRussia 2024
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

#pragma GCC optimize("unroll-loops,Ofast")

const int N = 500, M = 100, R = 22, inf = 1e9;
string t[N];

int n, m, k, r = 0;
pii rest[R];

set<int> nused;
vector<int> order;

ll mn = +inf;

template <typename T> struct arr {
  T a[N][N];
  T &operator[](pii idx) { return a[idx.first][idx.second]; }
};

arr<int> dist[N];
ll cur = 0;

void f() {
  int sz = int(order.size());
  // order.size() == k+1
  if (sz == k + 1) {
    mn = min(cur, mn);
    return;
  }
  if (cur >= mn) {
    return;
  }
  for (int k = *nused.begin(); k != +inf; k = *nused.upper_bound(k)) {
    int x = dist[order.back()][rest[k]];
    if (x == +inf) {
      continue;
    }
    nused.erase(k);
    order.push_back(k);
    cur += x;
    f();
    cur -= x;
    order.pop_back();
    nused.insert(k);
  }
  return;
}

vector<pii> adj(pii x) {
  auto [i, j] = x;
  vector<pii> answ, ch = {
                        {i - 1, j},
                        {i + 1, j},
                        {i, j - 1},
                        {i, j + 1},
                    };
  for (auto [i, j] : ch) {
    if (i >= 0 && i < n && j < m && j >= 0 && t[i][j] != '#') {
      answ.push_back({i, j});
    }
  }
  return answ;
}

void bfs(pii s, arr<int> &d) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[{i, j}] = +inf;
    }
  }
  d[s] = 0;
  queue<pii> q;
  q.push(s);
  while (!q.empty()) {
    pii x = q.front();
    q.pop();
    for (pii y : adj(x)) {
      if (d[y] > d[x] + 1) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  pii beg;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] == 'H') {
        beg = {i, j};
        break;
      }
    }
  }
  rest[r++] = beg;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] == 'R') {
        rest[r++] = {i, j};
      }
    }
  }

  for (int i = 0; i < r; i++) {
    bfs(rest[i], dist[i]);
  }

  for (int i = 1; i < r; i++) {
    nused.insert(i);
  }
  nused.insert(+inf);
  order.push_back(0);
  f();
  cout << mn;
}
