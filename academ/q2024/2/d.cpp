// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 2e5;
int a[N];
vector<int> b[N];

const int mod = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  int mx = 1;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }

  if (mx == 1) {
    int ans = 1;
    while (n > 2) {
      (ans *= 2) %= mod;
      n -= 2;
    }
    cout << ans << " " << ans << "\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    b[i].push_back(i);
  }

  int k = (n / 2) - 1;

  while (n > 2) {
    for (int i = 0; i + 2 < n; i++) {
      for (int x : b[i + 2]) {
        b[i].push_back(x);
      }
    }
    n -= 2;
  }

  map<int, int> m1, m2;

  for (int x : b[0]) {
    m1[x]++;
  }
  for (int x : b[1]) {
    m2[x]++;
  }
}
