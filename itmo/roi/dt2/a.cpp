// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

vector<int> norm(vector<int> a) {
  int g = abs(a[0]);

  for (auto &x : a) {
    g = gcd(abs(x), g);
  }

  for (auto &x : a) {
    x /= g;
  }

  if (a[0] < 0 || (a[0] == 0 && a[1] < 0)) {
    for (auto &x : a) {
      x *= -1;
    }
  }

  return a;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  map<vector<int>, int64_t> mp, mp2;

  int64_t s = 0;

  for (int i = 0; i < n; i++) {
    int t, a, b, c;
    cin >> t >> a >> b >> c;

    if (t == 1) {
      int q;
      cin >> q;
      s += q;
      mp[norm({a, b})] += q;
      mp2[norm({a, b, c})] += q;
    } else {
      if (mp2[norm({a, b, c})] != 0) {
        cout << "inf\n";
      } else {
        cout << (s - mp[norm({a, b})]) << "\n";
      }
    }
  }
}
