// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 200;
int a[N];

void gen(int i, int n, int k) {
  int64_t S = 0;
  for (int j = 0; j < i; j++) {
    S += a[i];
  }
  if (S > n) {
    return;
  }

  if (i == k) {
    // check
    int64_t S = 0;
    int64_t X = 0;
    for (int i = 0; i < k; i++) {
      S += a[i];
      X ^= a[i];
    }

    // for (int i = 0; i < k; i++) {
    //   cout << a[i] << " ";
    // }
    // cout << "\n";

    if (X == 0 && S == n) {
      for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
      }
      exit(0);
    }
    return;
  }

  for (int j = 1; j <= n; j++) {
    a[i] = j;
    gen(i + 1, n, k);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  gen(0, n, k);
  cout << "-1";
}
