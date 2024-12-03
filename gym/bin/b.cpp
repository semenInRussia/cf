// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N];
int n, k;

// check that x is minimum
//
// 1, 2, 3, 5, 8
// 1 2 3 100 1000
bool check(int x) {
  int l = a[0];
  int c = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] - l >= x) {
      c++;
      l = a[i];
    }
  }
  // cout << x << ": " << c << '\n';
  return c >= k;
}

int main() {
  freopen("cows.in", "r", stdin);
  freopen("cows.out", "w", stdout);
  // --

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = -1, r = a[n - 1] - a[0] + 100;
  while (r - l > 1) {
    int m = (r - l) / 2 + l;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l;
}
