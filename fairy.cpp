// Copyright 2024 semenInRussia
// CF https://codeforces.com/contest/19/problem/E
// #graphs #dfs *2900

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int maxn = 1e4, inf = 1e8;
// c[i] - amount of back-edges that connects white-->white vertexes
// n[i] - amount of back-edges that connects white<->black
set<pii> g[maxn];
bool used[maxn];
int cols[maxn];
int c[maxn], n[maxn], h[maxn];
map<pii, int> amap;

struct AnswEdge {
  // = 0 if the reason to edge was that it's connect two the same colored
  // vertexes
  // = 1 if otherwise
  bool reason;
  int id, depth;
};
vector<AnswEdge> answ;

// if n[v] == 0, c[v] > 0, then p-->v is answ

// get id of the edge
inline int get(pii p) { return amap[p]; }

bool check(int u, int col = 1) {
  used[u] = true;
  cols[u] = col;
  bool ok = true;
  for (pii e : g[u]) {
    int v = e.first;
    if (used[v]) {
      if (cols[u] == cols[v])
        ok = false;
    } else if (!check(v, 3 - col))
      ok = false;
  }
  return ok;
}

bool check_edge(int v, pii e, int id) {
  int a = e.first, b = e.second;
  g[a].erase({b, id}), g[b].erase({a, id});
  fill(used, used + maxn, 0);
  return check(v);
}

void dfs(int u, int p = -1) {
  used[u] = true;
  h[u] = (p == -1) ? 0 : h[p] + 1;
  cols[u] = (p == -1) ? 1 : 3 - cols[p];
  c[u] = n[u] = 0;
  for (pii e : g[u]) {
    int v = e.first;
    if (v == p || (used[v] && h[v] > h[u]))
      continue;

    if (used[v]) { // back-edge
      bool ok = cols[v] == cols[u];
      c[u] += ok, c[v] -= ok;
      n[u] += !ok, n[v] -= !ok;
    } else { // spam edge
      dfs(v, u);
      c[u] += c[v], n[u] += n[v];
    }
  }
}

void dfs2(int u, int p = -1) {
  used[u] = true;
  // n[p] == 0, n[u] > 0, c[u] = 0
  for (pii e : g[u]) {
    int v = e.first, id = e.second;
    if (v == p || (used[v] && h[v] > h[u]))
      continue;

    if (used[v]) { // back-edge
      if (cols[u] == cols[v])
        answ.push_back({0, id});
    } else { // span-edge
      if (n[v] == 0 && c[v] > 0 && p != -1)
        answ.push_back({1, get({u, p}), h[v]});
      dfs2(v, u);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pii> edges(m + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert({b, i});
    g[b].insert({a, i});
    edges[i] = {a, b};
    amap[{a, b}] = i, amap[{b, a}] = i;
  }

  int cnt = 0, ex = -1;
  for (int v = 0; v < n; v++)
    if (!used[v] && !check(v))
      ex = v, cnt++;

  if (cnt == 0) {
    // all edges are OK
    cout << m << '\n';
    for (int v = 1; v <= m; v++)
      cout << v << ' ';
  } else if (cnt == 1) {
    fill(used, used + n, 0);
    dfs(ex);
    fill(used, used + n, 0);
    dfs2(ex);

    // with reason=0, only if have one
    int cnt = 0, ans = 0;
    vector<int> answers;
    for (auto e : answ)
      if (e.reason == 0)
        cnt++, ans = e.id;
    if (cnt == 1)
      answers.push_back(ans);
    // if reason=2, find edge with minimum depth
    pii ans2 = {inf, inf}; // first is depth, second is id
    for (auto e : answ)
      if (e.reason == 1)
        ans2 = min(ans2, {e.depth, e.id});

    int id = ans2.second;
    if (id != inf && check_edge(ex, edges[id], id))
      answers.push_back(ans2.second);

    answers.erase(unique(answers.begin(), answers.end()), //
                  answers.end());
    sort(answers.begin(), answers.end());

    cout << answers.size() << "\n";
    for (auto el : answers)
      cout << el << ' ';
  } else
    cout << "0";
}
