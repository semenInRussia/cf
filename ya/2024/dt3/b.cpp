// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 6e5 + 100;

int64_t b[N];
int l[N], r[N];
int cntl[N], cntr[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }

  for (int i = 0; i < n; i++) {
    cntl[l[i]]++;
    cntr[r[i]]++;
  }

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      int64_t v = 1ll * cntl[i] * cntl[j];
      int64_t u = 1ll * cntr[i] * cntr[j];

      b[i + j] += v;
      b[i + j + 1] -= u;
    }
  }

  int64_t pref = 0;
  for (int i = 0; i <= 2 * m; i++) {
    pref += b[i];
    cout << pref << "\n";
  }
}
