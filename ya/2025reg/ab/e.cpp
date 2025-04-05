// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1.8e7 + 1;
int o[N];
int primes[N];

int cnt = 0; // amount of primes

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 2; i < N; i++) {
    if (o[i] == 0) {
      primes[cnt++] = i;
    }
    for (int j = 0; j < cnt && primes[j] * i < N; j++) {
      o[i * primes[j]] = primes[j];
    }
  }

  if (k > n * n) {
    cout << "-1";
    return 0;
  }

  if (k != n * n) {
    cout << "-1";
    return 0;
  }

  // cout << "cnt=" << cnt << "\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << primes[i * n + j] << " ";
    }
    cout << "\n";
  }
}
