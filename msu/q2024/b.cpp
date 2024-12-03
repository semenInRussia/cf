// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
vector<int> g[N];

bool used[N];

int dfs(int x) {
  used[x] = 1;
  int ans = 1;
  for (int y : g[x]) {
    if (used[y]) {
      continue;
    }
    ans += dfs(y);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    // a[i] => j
    g[i].push_back(j);
    g[j].push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    int v = dfs(i);
    if (v == 1) {
      continue;
    }
    ans += 2 * v + 1;
  }

  cout << ans;
}
