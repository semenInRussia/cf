// semenInRussia 2024
// https://codeforces.com/problemset/problem/1977/C
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
const int N = 2e3;
using ll = long long;

int a[N];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ll g = a[0];
    int mx = *max_element(a, a + n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      g = lcm(g, a[i]);
      if (g > mx)
        ans = n;
    }
    vector<int> divs;
    for (int i = 2; i * i <= mx; i++)
      if (mx % i == 0)
        divs.push_back(mx / i), divs.push_back(i);
    for (int d : divs) {
      if (count(a, a + n, d))
        continue;
      int cnt = 0, L = 0;
      for (int i = 0; i < n; i++)
        if (d % a[i] == 0)
          cnt++, L = L ? lcm(L, a[i]) : a[i];
      if (L == d)
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
}
