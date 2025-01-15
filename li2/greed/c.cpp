// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, bal;
  cin >> n >> bal;

  vector<pair<int, int>> a(n);

  for (auto &[p, s] : a) {
    cin >> p >> s;
  }

  int ans = 0;

  for (int j = 0; j < n; j++) {
    int64_t cur = a[j].first / 2 + a[j].second;

    if (cur > bal) {
      continue;
    }

    vector<int> b(n);

    for (int i = 0; i < n; i++) {
      b[i] = a[i].first + a[i].second;
    }

    b.erase(find(b.begin(), b.end(), a[j].first + a[j].second));

    sort(b.begin(), b.end());

    int sz = (int)b.size();

    int op = 1;

    for (int i = 0; i < sz; i++) {
      if (cur + b[i] > bal) {
        continue;
      }
      op++;
      cur += b[i];
    }

    ans = max(ans, op);
  }

  cout << ans;
}
