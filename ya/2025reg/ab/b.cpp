// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1e5 + 100;
const int L = 30;
int cnt[L + 10];
int a[N];

int main() {
  int n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << "-1";
    return 0;
  }

  int S = 0;

  if (n % 2 == 1) {
    cout << "-1";
    return 0;
  }

  for (int i = 1; i < L; i++) {
    if ((n >> i) & 1) {
      cnt[i - 1] += 2;
      S += 2;
    }
  }

  while (S < k) {
    int old = S;
    for (int i = L - 1; i > 0; i--) {
      int x = min(cnt[i] / 2, (k - cnt[i - 1]) / 4);
      cnt[i] -= 2 * x;
      cnt[i - 1] += 4 * x;
      S += 2 * x;
    }
    if (S == old) {
      break;
    }
  }

  if (S < k) {
    cout << "-1";
    return 0;
  }

  int r = 0;

  for (int i = 0; i < L; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      a[r % k] ^= 1 << i;
      r++;
    }
  }

  for (int i = 0; i < k; i++) {
    cout << a[i] << " ";
  }
}
