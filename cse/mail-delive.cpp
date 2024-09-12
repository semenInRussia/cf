// semenInRussia 2024
// https://cses.fi/problemset/task/1691
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 2e5;
set<int> g[N];

vector<int> answ;
void euler(int x) {
  while (!g[x].empty()) {
    int y = *g[x].begin();
    g[x].erase(y);
    g[y].erase(x);
    euler(y);
  }
  answ.push_back(x);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }

  bool ok = 1;
  for (int i = 0; i < n && ok; i++) {
    if (g[i].size() % 2) {
      ok = 0;
    }
  }
  euler(0);
  if (answ.size() != size_t(m + 1)) {
    ok = 0;
  }
  if (!ok) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  for (int x : answ) {
    cout << (x + 1) << ' ';
  }
}
