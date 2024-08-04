// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5010, M = 1e5 + 1;
using ll = long long;
const ll inf = (ll)1e18;

int x[N], c[M];
ll memo[N];

// answer for [l; n)
int n;
ll f(int l) {
  if (l == n - 1)
    return c[1];
  ll &ans = memo[l];
  if (ans != -1)
    return ans;
  ll pref = c[1];
  ans = pref + f(l + 1);
  for (int i = l + 1; i < n; i++) {
    ans = min(ans, pref + f(i));
    pref = c[x[i] - x[l] + 1];
  }
  pref = c[x[n - 1] - x[l] + 1];
  ans = min(ans, pref);
  return ans;
}

int main() {
  int m;
  cin >> n >> m;
  fill(memo, memo + n + 2, -1);
  fill(c, c + M, 1e9);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x, x + n);
  for (int w = 1; w <= m; w++)
    cin >> c[w];
  for (int i = m; i > 0; i--)
    c[i - 1] = min(c[i], c[i - 1]);
  cout << f(0);
}
