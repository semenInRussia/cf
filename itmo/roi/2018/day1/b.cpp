// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 505;
int a[N];
vector<int> t[N], pos[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    t[i].resize(n);
    for (int &x : t[i]) {
      cin >> x;
      --x;
    }
    pos[i].resize(n);
    for (int j = 0; j < n; j++) {
      pos[i][t[i][j]] = j;
    }
  }

  int p;
  cin >> p;

  vector<int> stable;
  for (int i = 0; i < n; i++) {
    if (t[i][0] == i) {
      stable.push_back(i);
    }
  }

  if (p == 1) {
    cout << stable.size() << "\n";
    for (int x : stable) {
      cout << (x + 1) << " ";
    }
    return;
  }

  vector<int> ans;

  // first:
  // - iterate i
  // - eat all that we can
  // - add all that we still can eat
  // - for every eaten cell we can ask: if there no stable, ans=true

  for (int i = 0; i < n; i++) {
    vector<int> used(n);
    used[i] = true;

    for (int l = 0; l < n; l++) {
      if (pos[l][i] < pos[l][l] && !used[l]) {
        used[l] = true;
      }
    }

    bool ok = false;

    for (int x = 0; x < n; x++) {
      if (!used[x]) {
        continue;
      }
      bool cur = true;
      for (int y : t[x]) {
        if (y == i) {
          break;
        }
        if (binary_search(stable.begin(), stable.end(), y)) {
          cur = false;
        }
      }
      if (cur) {
        ok = true;
      }
    }

    if (ok) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << "\n";
  for (int x : ans) {
    cout << (x + 1) << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n\n";
  }
}
