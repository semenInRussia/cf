// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 32;

int a[N][N];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = i * n + j;
    }
  }

  int64_t s = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < n; j++) {
      s += a[i][j] ^ a[i][j + 1];
    }
  }

  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j < n; j++) {
      s += a[i][j] ^ a[i + 1][j];
    }
  }

  assert(s <= 48000);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < n; j++) {
      cout << (a[i][j] ^ a[i][j + 1]) << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (a[i][j] ^ a[i + 1][j]) << " ";
    }
    cout << "\n";
  }

  cout.flush();

  int cur = 0; // (0, 0)

  while (k--) {
    int x;
    cin >> x;
    cur ^= x;
    int i = cur / n;
    int j = cur % n;
    cout << (i + 1) << ' ' << (j + 1) << endl;
  }
}
