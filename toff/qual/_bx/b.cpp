// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#pragma GCC optimize("unroll-loops,Ofast")

const int N = 100, mod = 998244353, inf = 1e9;
pii p[N];
bool used[N];
int col[N], dist[N];

int main() {
  int n;
  cin >> n;
  int num = 0;
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    // find min distance
    for (int j = 0; j < n; j++) {
      if (j == i) {
        dist[j] = +inf;
        continue;
      }
      dist[j] = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
    }
    int mn = *min_element(dist, dist + n);
    for
  }
}
