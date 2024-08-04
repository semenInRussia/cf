// semenInRussia 2024
// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/L
#include <iostream>
using namespace std;
const int N = 6e4 + 1;

// we have:
// a : {1, 2, 3, 4, ..., n}
// b : {2, 3, 4, 5, ..., n+1}

// find amount of b placements, that
// b[i] % i == 0
int dp[N];
int ans = 0;

int f(int n) {
  if (n == 1)
    return 1;
  int &ans = dp[n];
  if (ans != -1)
    return ans;
  ans = 0;
  for (int i = 1; i <= n; i++)
    if ((n + i) % i == 0)
      ans += f(n - i);
  return ans;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // fill(dp, dp + N, -1);
  //--

  int n;
  cin >> n;
  // cout << f(n);
  dp[0] = 1; // Базовый случай: один способ заполнить массив длиной 0

  // Перебираем все позиции массива
  for (int i = 1; i <= n; i++) {
    // Перебираем все числа от 2 до N + 1
    for (int j = 2; j <= n + 1; j++) {
      // Проверяем, делится ли число j на i
      if (j % i == 0) {
        dp[i] += dp[i - 1];
      }
    }
  }

  cout << dp[n];
}
