// semenInRussia 2024
// https://cses.fi/problemset/task/2220
// https://codeforces.com/blog/entry/53960
// --
// I am reading this article at codeforces about Digit Dynamic
// Programming and try to solve the CSES problem after reading
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 20, D = 10;
using ll = long long;

// f[i][prv][small]

ll memo[N + 1][D][2];
vector<int> num;

ll f(int i, int prv, bool small) {
  ll &ans = memo[i][prv][small];
  if (ans != -1)
    return ans;
  if (i == int(num.size()))
    return ans = 1;

  int lim = small ? D : num[i];
  ans = 0;
  for (int d = 0; d < lim; d++) {
    if (d != prv) {
      ans += f(i + 1, d, 1);
    }
  }
  if (!small && prv != num[i]) {
    ans += f(i + 1, num[i], 0);
  }

  return ans;
}

// <x
ll before(ll x) {
  if (x <= 1) {
    return x;
  }
  x--;
  for (int i = 0; i <= N; i++) {
    for (int d = 0; d < D; d++) {
      for (int small = 0; small < 2; small++) {
        memo[i][d][small] = -1;
      }
    }
  }

  num.clear();
  ll t = x;
  while (t) {
    num.push_back(t % 10);
    t /= 10;
  }
  reverse(num.begin(), num.end());

  ll ans = 1; // 0
  for (int d = 1; d < num[0]; d++) {
    ans += f(1, d, 1);
  }
  ans += f(1, num[0], 0);
  for (int j = 1; j < num.size(); j++) { // numbers with less size
    ans += f(j, 0, 1);
  }
  return ans;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << before(b + 1) - before(a);
}
