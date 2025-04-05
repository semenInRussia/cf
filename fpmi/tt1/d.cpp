// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

// idea:
// 1. fill val[]
// 2. find centroids
// 3. solve:
//    - add every val
//    - fill s[] - sum of that we must add
//    - s[x] - cnt[p[x]]

const int N = 2e5 + 100;
vector<int> g[N];
int val[N], a[N];

void dfs(int x, int fa = -1) {
  val[x] = fa == -1 ? 0 : val[fa];
  val[x] ^= 1 << a[x];
  for (int y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }
}

bool used[N];
int sz[N];

void sizes(int x, int fa = -1) {
  sz[x] = 1;
  for (int y : g[x]) {
    if (y != fa && !used[y]) {
      sizes(y, x);
      sz[x] += sz[y];
    }
  }
}

int centr(int x, int n, int fa = -1) {
  for (int y : g[x]) {
    if (!used[y] && sz[y] > n / 2 && y != fa) {
      return centr(y, n, x);
    }
  }
  return x;
}

const int K = 't' - 'a' + 1;
int cnt[1 << K];

int64_t s[N], answ[N];

void solve(int x) {}

int main() {
  int n;
  cin >> n;
}
