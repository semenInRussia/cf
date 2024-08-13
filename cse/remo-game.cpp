// semenInRussia 2024
// https://cses.fi/problemset/task/1097
#include <iostream>
using namespace std;
using ll = long long;

const int N = 5010;
ll b[N];
int a[N];

bool mark[N][N];
ll memo[N][N];

ll f(int l, int r) { // max score for [l; r]
  ll &ans = memo[l][r];
  if (mark[l][r])
    return ans;
  mark[l][r] = 1;
  if (l == r)
    return ans = a[l];
  ll sum = b[r + 1] - b[l];
  ll op1 = sum - f(l + 1, r);
  ll op2 = sum - f(l, r - 1);
  return ans = max(op1, op2);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  cout << f(0, n - 1);
}
