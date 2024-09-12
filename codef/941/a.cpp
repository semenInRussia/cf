// Copyright 2024 semenInRussia

#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>

using namespace std;

const int maxn = 101;
int c[maxn], cnt[maxn];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    fill(cnt, cnt + maxn, 0);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      cnt[c[i]]++;
    }

    // alg:
    int acc = 0;
    sort(cnt, cnt + maxn);

    for (int i = maxn - 1; i >= 0; i--) {
      acc += (cnt[i] / k) * (k - 1);
      if ((cnt[i] % k) > 0 && (acc + cnt[i] % k >= k))
        acc -= k - (cnt[i] % k), cnt[i] = 0, acc += k - 1;
      cnt[i] %= k;
    }
    // - if > k, update acc += (cnt[i] / k) * (k - 1)
    // - if (cnt[i] % k) > 0, try use acc
    // - if (acc + cnt[i] % k >= k), use acc

    for (int i = maxn - 1; i >= 0; i--) {
      if (!cnt[i])
        continue;
      if (acc + cnt[i] >= k)
        acc -= k - cnt[i], acc += k - 1, cnt[i] = 0;
    }
    acc = min(acc, k - 1);

    cout << (acc + accumulate(cnt, cnt + maxn, 0)) << endl;
  }
}
