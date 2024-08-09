// semenInRussia 2024
// https://cses.fi/problemset/task/1618
#include <iostream>
using namespace std;
using ll = __int128;

int solve(int n) {
  int ans = 0;
  for (ll p5 = 5; p5 <= n; p5 *= 5)
    ans += n / p5;
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n);
}
