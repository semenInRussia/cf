// semenInRussia 2024
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 60;
using ll = long long;
ll memo[N][N] = {{-1}};

ll f(int i, int j) {
  if (i < 1 || j < 1)
    return 0;
  ll &ans = memo[i][j];
  if (ans == -1)
    ans = f(i - 2, j - 1) + f(j - 2, i - 1);
  return ans;
}
int main() {
  freopen("knight.out", "w", stdout);
  freopen("knight.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n + 1; i++)
    fill(memo[i], memo[i] + m + 2, -1);
  memo[1][1] = 1;
  cout << f(n, m);
}
