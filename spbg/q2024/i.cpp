// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 3e5 + 1000;
pair<int, int> p[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (p[i].first != p[j].first) {
        continue;
      }

      for (int k = 0; k < n; k++) {
        if (p[k].second != p[i].second) {
          continue;
        }

        for (int l = 0; l < n; l++) {
          if (p[l].first != p[k].first || p[l].second != p[j].second) {
            continue;
          }

          int64_t op = 1ll * abs(p[i].second - p[j].second) *
                       abs(p[k].first - p[i].first);
          ans = max(ans, op);
        }
      }
    }
  }

  cout << ans;
}
