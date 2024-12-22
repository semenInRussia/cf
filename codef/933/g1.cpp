// semenInRussia 2024
// http..
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 100;
int r[N];
bool used[N];
bool cycle[N];
int d[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> r[i];
    r[i]--;
    d[i] = 0;
    cycle[i] = used[i] = 0;
  }

  int ans = 2;

  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }

    vector<int> path;

    int j = i;
    while (!used[j]) {
      used[j] = 1;
      path.push_back(j);
      j = r[j];
    }

    auto it = find(path.begin(), path.end(), j);

    if (it == path.end()) {
      continue;
    }

    for (; it != path.end(); it++) {
      cycle[*it] = 1;
      d[*it] = 0;
    }
  }

  fill(used, used + n, 0);

  for (int i = 0; i < n; i++) {
    if (used[i] || cycle[i]) {
      continue;
    }

    vector<int> path;
    int j = i;
    while (!cycle[j] && !used[j]) {
      used[j] = 1;
      path.push_back(j);
      j = r[j];
    }

    if (path.empty()) {
      continue;
    }

    for (j = int(path.size()) - 1; j >= 0; j--) {
      d[path[j]] = d[r[path[j]]] + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    ans = max(ans, d[i] + 2);
  }

  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
