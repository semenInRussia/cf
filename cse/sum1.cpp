// semenInRussia 2024
// https://cses.fi/problemset/task/166
// https://cses.fi/problemset/task/167
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int N = 2e5;
ll b[N];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    b[i] = b[i - 1] + x;
  }

  map<ll, int> s = {{0, 1}};
  ll ans = 0;
  for (int r = 1; r <= n; r++) {
    // sum = b[r] - b[l], b[l] = b[r] - sum
    ans += s[b[r] - x];
    s[b[r]]++;
  }
  cout << ans;
}
