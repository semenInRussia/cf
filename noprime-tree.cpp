// semenInRussia 2024
// https://codeforces.com/contest/2040/problem/D
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

using ll = long long;

const int N = 5e5;
bool prime[N];

int a[N];

vector<int> g[N];

set<int> c;

int top(int x) {
  int ans = -1;
  for (int y : c) {
    if (abs(x - y) != 2) {
      ans = y;
      break;
    }
  }
  if (ans == -1) {
    return x + 1;
  }
  c.erase(ans);
  return ans;
}

void dfs(int x, int fa = -1) {
  a[x] = top(fa == -1 ? -100 : a[fa]);
  for (int y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    g[i].clear();
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  c.clear();
  for (int i = 1; i <= n; i++) {
    c.insert(i * 2 - 1);
  }

  a[0] = 1;

  dfs(0);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int main() {
  for (int i = 2; i < N; i++) {
    prime[i] = 1;
  }

  for (ll i = 2; i < N; i++) {
    for (ll j = i * i; j < N; j += i) {
      prime[j] = 0;
    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
