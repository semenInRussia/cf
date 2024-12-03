// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;

const int N = 70;
int64_t p[N];

int f(int n, int64_t i) {
  // note that return numbers inside characters
  auto sz = p[n];
  assert(i < sz);
  assert(sz & 1);

  if (sz == 1) {
    return 0; // валет
  }
  auto mid = sz / 2;
  if (mid == i) {
    return 3; // туз
  }
  if (i < mid) {
    return f(n - 1, i);
  } else {
    return (f(n - 1, sz - i - 1) + 1) % 4;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  int64_t k;
  cin >> n >> k;
  p[0] = 1;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] * 2 + 1;
  }
  string s = "ВДКТ";
  int j = f(n - 1, k);
  k // cout << j << "\n";
          cout
      << s[j] << '\n';
}
