// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 2e5;
int a[N];
map<int, vector<int>> occ;

void solve() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = (n + 1) / 2 + 1;

  for (int j = 0; j < n; j++) {
    int l1 = (j + 2) / 2;
    int r1 = min((j + 1 + n - k) / 2 + 1, j + 1);

    int l2 = (k - n + j + 2) / 2;
    int r2 = min((j + 2) / 2, j + 1);

    pair<int, int> p[2] = {{l1, r1}, {l2, r2}};

    for (auto [l, r] : p) {
      l = max(1, l);

      if (r - l <= 0) {
        continue;
      }

      if (a[j] != l) {
        ans = min(ans, l);
      } else if (r - l > 1) {
        ans = min(ans, l + 1);
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
