// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int W = 10;
int c[] = {5, 9, 3, 4, 100, 3}, w[] = {5, 1, 4, 1, 11, 1};
int n = sizeof(w) / sizeof(w[0]);

using pii = pair<int, int>;
using ll = long long;
map<pii, ll> lazy;
ll f(int rest, int i) {
  // return the best C, using Rest weight and things with j>=i
  if (i == n)
    return 0;
  if (lazy.count({rest, i}))
    return lazy[{rest, i}];
  ll ret = f(rest, i + 1);
  if (rest >= w[i])
    ret = max(ret, f(rest - w[i], i + 1) + c[i]);
  return lazy[{rest, i}] = ret;
}
int main() {
  int ans = f(W, 0);
  cout << ans;
}
