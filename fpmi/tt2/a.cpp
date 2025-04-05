// semenInRussia 2025
#include <bitset>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// 1. find all prime numbers
const int N = 1e5;
int prime[N];

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < N; i++) {
    prime[i] = true;
  }

  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      prime[j] = false;
    }
  }

  int k = 0;
  vector<int> p(n);

  for (int i = 2; i < N && k < n; i++) {
    if (prime[i]) {
      p[k++] = i;
    }
  }

  vector<int64_t> ans(n, 1);

  for (int i = 0; i < 3; i++) {
    int x = p[i];
    for (int j = 0; j < n; j++) {
      if (j != i) {
        ans[j] *= x;
      }
    }
  }

  if (n > 3) {
    for (int j = 4; j < n; j++) {
      int v = p[j - 1];
      ans[j] *= v;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      assert(gcd(ans[i], ans[j]) != 1);
    }
  }

  int g = 0;
  for (int v : ans) {
    g = gcd(v, g);
  }
  assert(g == 1);

  for (auto x : ans) {
    cout << x << "\n";
  }
}
