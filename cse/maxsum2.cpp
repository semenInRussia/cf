// semenInRussia 2024
// https://cses.fi/problemset/task/1644
#include <iostream>
#include <set>
using namespace std;
using ll = long long;

const int N = 2e5;
int x[N];
ll s[N];

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
    s[i + 1] = s[i] + x[i];
  }

  multiset<ll> q; // set of possible left bounds
  ll ans = s[a];
  for (int i = a; i <= n; i++) {
    // check subarrays
    //
    // [i-a, i) -> [i-b, i)
    // left bound:
    // r-l >= a, r-l <= b
    // l <= r-a
    // l >= r-b
    q.insert(s[i - a]);
    if (i > b)
      q.erase(q.find(s[i - b - 1]));
    ans = max(ans, s[i] - *q.begin());
  }
  cout << ans;
}
