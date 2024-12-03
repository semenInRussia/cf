// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

#pragma GCC optimize("unroll-loops")

inline int f(int n) {
  if (~n & 1) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}

int when(int x) { // return amount of apply x=f(x) while x != 1
  int t = 0;
  while (x != 1) {
    x = f(x);
    t++;
  }
  return t;
}

const int N = 1e4 + 5;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) { // O(n * 178)
    a[i] = when(a[i]);
  }

  int ans = *max_element(a, a + n);
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (a[i] % 3 != a[i - 1] % 3) {
      ok = false;
    }
  }

  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << ' ';
  // }
  // cout << '\n';

  if (!ok) {
    ans = -1;
  }
  cout << ans;
}
