// semenInRussia 2024
// https://cses.fi/problemset/task/1662
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int N = 2e5 + 100;
ll b[N];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    b[i] = b[i - 1] + x;
  }

  ll ans = 0;
  // b[r] - b[l] = 0 \mod n
  map<int, int> cnt;
  cnt[0] = 1;

  // cnt[m] - amount of prefix sums with modulo=m
  for (int i = 1; i <= n; i++) {
    int mod = ((b[i] % n) + n) % n;
    ans += cnt[mod];
    cnt[mod]++;
  }
  cout << ans;
}
