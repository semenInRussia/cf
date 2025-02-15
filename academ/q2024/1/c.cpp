// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 1e7 + 100;
int divs[N];
int o[N];
int primes[N];

int main() {
  int n;
  cin >> n;

  o[0] = 1;
  o[1] = 1;

  int sz = 0;

  for (int i = 2; i <= N; i++) {
    if (o[i] == 0) {
      primes[sz++] = i;
    }
    for (int k = 0; k < sz; k++) {
      int j = primes[k];
      if (j > i || i * j >= N) {
        break;
      }
      o[j * i] = j;
    }
  }

  divs[1] = 1;
  for (int i = 2; i <= n; i++) {
    divs[i] = 2;
    if (o[i] == 0) {
      continue;
    }
    int x = i;
    int c = 1;
    while (x % o[i] == 0) {
      c++;
      x /= o[i];
    }
    divs[i] = divs[x] * c;
  }

  int64_t ans = 0;

  for (int c = 1; c <= n; c++) {
    ans += c - 1 + divs[c];
    if (c == 4) {
      ans--;
    }
  }

  cout << ans;
}
