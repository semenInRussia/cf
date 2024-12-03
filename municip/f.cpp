// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 500;
bool prime[N];

int main() {
  for (int i = 0; i < N; i++) {
    prime[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    for (int j = i * i; j < N; j += i) {
      prime[j] = 0;
    }
  }

  int n;
  cin >> n;

  vector<int> p;
  for (int i = 2; i < N && int(p.size()) < n; i++) {
    if (prime[i]) {
      p.push_back(i);
    }
  }

  reverse(p.begin(), p.end());

  // last a; a < b, b - a - min
  // last a; a < (M/a), {(M/a) - a} - min

  int M = (1 << n) - 1;

  int st = -1;
  for (int a = 0; a < (1 << n); a++) {
    int b = M ^ a;
    if (a < b) {
      st = max(st, a);
    }
  }

  int64_t ans = 1;
  for (int j = 0; j < n; j++) {
    cout << ((st >> j) & 1);
    if ((st >> j) & 1) {
      ans *= p[j];
    }
  }
  cout << "\n";

  cout << ans;
}
