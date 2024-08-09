// semenInRussia 2024
// https://cses.fi/problemset/task/1092
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll sum = 1ll * (1 + n) * n / 2;
  if (sum & 1) {
    cout << "NO";
    return 0;
  }

  ll h = sum / 2, cur = 0;
  vector<int> a;
  for (int i = n; i > 0 && cur < h; i--)
    if (cur + i <= h)
      a.push_back(i), cur += i;

  reverse(a.begin(), a.end());
  cout << "YES\n" << a.size() << '\n';
  for (int x : a)
    cout << x << ' ';

  cout << '\n' << n - a.size() << '\n';
  for (int i = 1; i <= n; i++)
    if (!binary_search(a.begin(), a.end(), i))
      cout << i << ' ';
}
