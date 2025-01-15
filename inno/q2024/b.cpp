// semenInRussia 2024
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>

using namespace std;

const int N = 2e5;
int a[N], b[N];

bool used[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n;
  cin >> n;

  if (n == 2) {
    int a1, a2;
    int b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int ans = min(a1, b2) + min(a2, b1);
    cout << ans;

    return 0;
  }

  // algorithm;
  // - choose value with minimum b[i], a[i] > 0
  // - b[j]--, a[i]--

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int ans = 0;

  const int inf = 1e9 + 5;

  while (1) {
    // find j, that b[j] - minimum, a[j] - maximum

    int i = -1;

    int min1 = +inf, min2 = +inf;

    for (int j = 0; j < n; j++) {
      if (a[j] != 0) {
        if (i == -1 || b[j] < b[i]) {
          i = j;
        }
        auto op = b[j];
        if (op <= min1) {
          min2 = min1;
          min1 = op;
        } else if (op < min1) {
          min1 = op;
        }
      }
    }

    if (i == -1) {
      break;
    }

    auto d = min(a[i], max(1, min2 - min1));

    a[i] -= d;

    if (d == 0) {
      break;
    }

    bool stop = false;

    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      if (b[j] == 0) {
        stop = true;
      }

      b[j] -= d;
    }

    if (stop) {
      break;
    }

    ans += d;
  }

  cout << ans;
}
