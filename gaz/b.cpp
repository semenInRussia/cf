// semenInRussia 2024
// https://contest.yandex.ru/contest/53964/problems/B/
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 305;
vector<int> t[N], g[N];

// return true, if every element of a is within of b

bool part(int v, int u) {
  auto &a = t[v];
  auto &b = t[u];

  int j = 0;
  int k = (int)b.size();

  for (int x : a) {
    while (j < k && b[j] < x) {
      j++;
    }
    if (j == k || b[j] != x) {
      return false;
    }
  }

  return true;
}

int ti = 0;
int o[N];
bool used[N];

void topsort(int x) {
  if (used[x]) {
    return;
  }

  used[x] = true;

  for (int y : g[x]) {
    topsort(y);
  }

  o[ti++] = x;
}

int dfs(int x) {
  if (used[x]) {
    return 0;
  }

  used[x] = true;

  int ans = 0;
  int cnt = 0;

  for (int y : g[x]) {
    int v = dfs(y);
    ans += v;
    cnt += v > 0;
  }

  return ans + (cnt == 0);
}

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    t[i].resize(m);
    for (int &x : t[i]) {
      cin >> x;
    }

    sort(t[i].begin(), t[i].end());
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && part(i, j)) {
        g[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    topsort(i);
  }

  int ans = 0;

  fill(used, used + n, false);

  for (int i = 0; i < n; i++) {
    ans += dfs(o[n - i - 1]);
  }

  cout << ans;
}
