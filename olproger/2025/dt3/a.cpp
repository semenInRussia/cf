// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 2e5;
int d[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  // max sum of d[i];
  // min last d[i]

  // we can do sum X; answer is (k + m)

  sort(d, d + n);

  int64_t ans = m;

  for (int i = 0; i < n; i++) {
    if (d[i] <= m) {
      m -= d[i];
      ans++;
    }
  }

  cout << ans;
}
