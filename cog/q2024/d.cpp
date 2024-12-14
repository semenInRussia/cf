// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 2e5;
int p[N];

int ans[N];

bool bad[N];

bool used[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    used[i] = bad[i] = 0;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int j;
    cin >> j;
    j--;
    bad[j] = 1;
  }

  vector<int> path, badpath, badlone, lone;

  for (int x = 0; x < n; x++) {
    if (used[x]) {
      continue;
    }

    path.clear();
    badpath.clear();

    while (!used[x]) {
      used[x] = 1;
      if (bad[x]) {
        badpath.push_back(x);
      } else {
        path.push_back(x);
      }
      x = p[x];
    }

    int sz = path.size();

    if (sz == 1) {
      lone.push_back(path[0]);
    } else {
      for (int j = 0; j < sz; j++) {
        ans[path[j]] = path[(j + 1) % sz];
      }
    }

    sz = badpath.size();
    if (sz == 1) {
      badlone.push_back(badpath[0]);
    } else {
      for (int j = 0; j < sz; j++) {
        ans[badpath[j]] = badpath[(j + 1) % sz];
      }
    }
  }

  // cout << used[4] << "\n";

  int sz = badlone.size();
  for (int j = 0; j < sz; j++) {
    ans[badlone[j]] = badlone[(j + 1) % sz];
  }

  if (sz == 1) {
    // find OK node, who ans[x] != p[x]
    int y = -1;
    for (int x = 0; x < n; x++) {
      if (x == badlone[0]) {
        continue;
      }
      if (bad[x]) {
        y = x;
      }
      if (bad[x] && ans[x] != p[x]) {
        break;
      }
    }

    int w = ans[y];
    ans[y] = badlone[0];
    ans[badlone[0]] = w;
  }

  sz = lone.size();
  for (int j = 0; j < sz; j++) {
    ans[lone[j]] = lone[(j + 1) % sz];
  }

  if (sz == 1) {
    int y = -1;
    for (int x = 0; x < n; x++) {
      if (x == lone[0]) {
        continue;
      }
      if (!bad[x]) {
        y = x;
      }
      if (!bad[x] && ans[x] != p[x]) {
        break;
      }
    }

    int w = ans[y];
    ans[y] = lone[0];
    ans[lone[0]] = w;
  }

  for (int i = 0; i < n; i++) {
    cout << (ans[i] + 1) << " ";
  }
  cout << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
