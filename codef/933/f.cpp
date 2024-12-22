// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 2e5;

int a[N], b[N];

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int64_t A = 0;

  for (int i = 0; i < n; i++) {
    A += a[i];
  }

  int64_t B = 0;

  for (int i = 0; i < m; i++) {
    B += b[i];
  }

  sort(b, b + m);

  int64_t S = A * B;

  for (int i = 0; i < q; i++) {
    int64_t x;
    cin >> x;
    x = S - x;
  }
}
