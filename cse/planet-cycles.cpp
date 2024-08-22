// semenInRussia 2024
// https://cses.fi/problemset/task/1751
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5, inf = 1e9 + 5;
// cycle[x] - size of cycle which have x
int t[N], used[N], cycle[N], answ[N];

void dfs(int x) {
  answ[x] = +inf;
  used[x] = 1;
  if (cycle[x] != -1) {
    answ[x] = cycle[x];
  }

  if (!used[t[x]]) {
    dfs(t[x]);
  }

  answ[x] = min(answ[x], answ[t[x]] + 1);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i]--;
    cycle[i] = -1;
  }

  // fill cycle[x]
  // cycle[x] - size of cycle which have x or -1 if isn't in cycle
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    vector<int> path;
    int x;
    for (x = i; !used[x]; x = t[x]) {
      used[x] = 1;
      path.push_back(x);
    }

    int beg = find(path.begin(), path.end(), x) - path.begin();
    for (int i = beg; i < (int)path.size(); i++) {
      cycle[path[i]] = int(path.size()) - beg;
    }
  }

  // fill answ[] - distance to cycle
  fill(used, used + n, 0);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << answ[i] << ' ';
  }
}
