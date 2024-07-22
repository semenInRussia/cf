// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 2003;
using ll = long long;
ll memo[N][N];
// f(p, mx) - amount of sets with power=p and max=mx
ll f(int p, int mx) { // N*N
  if (mx >= p)
    return mx == p;
  ll &ans = memo[p][mx];
  if (ans != -1)
    return ans;
  ans = 0;
  int rst = p - mx;
  for (int mx2 = 1; mx2 * 2 <= mx && mx2 <= rst; mx2++) // min(mx/2, p-mx)
    ans += f(rst, mx2);
  return ans;
}

int main() {
  freopen("peacefulsets.in", "r", stdin);
  freopen("peacefulsets.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      memo[i][j] = -1;
  ll ans = 0;
  for (int mx = 1; mx <= n; mx++)
    ans += f(n, mx);
  cout << ans;
}
