// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int N = 1e8 + 100;
int primes[N / 2];
int o[N];
int b[N];

int k;

bool is_prime(int x) { return binary_search(primes, primes + k, x); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  for (int i = 2; i < N; i++) {
    if (o[i] == 0) {
      primes[k++] = i;
    }

    for (int j = 0; j < k && primes[j] * i < N; j++) {
      o[primes[j] * i] = primes[j];
    }
  }

  for (int i = 0; i < k; i++) {
    int x = primes[i];
    if (x == 1) {
      continue;
    }
    b[x]++;
    if (x * 2 + 1 < N) {
      b[x * 2 + 1]--;
    }
  }

  o[0] = 0;
  for (int i = 1; i < N; i++) {
    o[i] = o[i - 1] + b[i - 1];
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    int ans = o[x];
    if (is_prime(x - __builtin_popcount(x))) {
      ans++;
    }
    // cout << x << ". " << ans << "\n";
    cout << ans << "\n";
  }
}
