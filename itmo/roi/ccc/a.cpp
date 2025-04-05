// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1 << 16;
int b[N], a[N], ad[N];

int pop[N];

int cnt[20];

int main() {
  for (int i = 1; i < N; i++) {
    pop[i] = pop[i / 2];
    if (i & 1) {
      pop[i]++;
    }
    cnt[pop[i]]++;
  }

  for (int i = 0; i < 20; i++) {
    cout << cnt[i] << "\n";
  }

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + pop[a[i]];
  }

  bool was = false;

  for (int j = 0; j < q; j++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, k;
      cin >> l >> r >> k;
      --l;
      ad[l] += k;
      ad[r] -= k;
      was = true;
    } else {
      if (was) {
        was = false;
        int pref = 0;
        for (int i = 0; i < n; i++) {
          pref += ad[i];
          ad[i] = 0;
          a[i] += pref;
        }
        for (int i = 0; i < n; i++) {
          b[i + 1] = b[i] + pop[a[i]];
        }
      }
      int l, r;
      cin >> l >> r;
      --l;
      cout << b[r] - b[l] << "\n";
    }
  }
}
