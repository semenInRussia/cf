// semenInRussia 2024
// https://cses.fi/problemset/task/1090
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e5;
int a[N];
bool used[N];

// find maximum j: cur + a[j] <= x
int find(int l, int r, int cur, int x) {
  l--;
  int ans = -1;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (a[m] + cur <= x)
      l = m, ans = max(ans, m);
    else
      r = m;
  }
  return ans < 0 ? r : ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int r = n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;
    int j = find(i + 1, r, a[i], x);
    if (j < r && a[j] + a[i] <= x) {
      used[j] = 1;
      r = j;
    }
    ans++;
  }

  cout << ans;
}
