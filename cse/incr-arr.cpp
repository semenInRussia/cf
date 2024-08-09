// semenInRussia 2024
// https://cses.fi/problemset/task/1094
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += max(0, a[i - 1] - a[i]);
    a[i] = max(a[i - 1], a[i]);
  }
  cout << ans;
}
