// semenInRussia 2024
// https://cses.fi/problemset/task/1623
#include <iostream>
using namespace std;
using ll = long long;
const ll inf = 1e18;

const int N = 25;
int n, p[N];
ll ans = +inf;
ll f(int i, ll a, ll b) {
  if (i == n)
    return abs(a - b);
  return min(f(i + 1, a + p[i], b), f(i + 1, a, b + p[i]));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  cout << f(0, 0, 0);
}
