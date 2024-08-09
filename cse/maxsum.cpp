// semenInRussia 2024
// https://cses.fi/problemset/task/1643
#include <cstdio>
using namespace std;
using ll = long long;

#pragma GCC optimize("Ofast,unroll-loops")

ll mn = 0, sm = 0, ans = -1e9;
int n, x;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    sm += x;
    if (sm - mn > ans)
      ans = sm - mn;
    if (sm < mn)
      mn = sm;
  }
  printf("%lld", ans);
}
