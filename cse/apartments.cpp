// semenInRussia 2024
// https://cses.fi/problemset/task/1084
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e5;
int a[N], b[N];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  sort(b, b + m);
  int cur = 0; // the interval of apartements [0; cur) is not free

  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = cur;
    for (; j < m && b[j] < a[i] - k; j++) {
    }
    bool ok = j < m && b[j] <= a[i] + k;
    if (ok) {
      ans++;
      cur = min(m, j + 1);
    }
  }
  cout << ans;
}
