// semenInRussia 2024
// https://cses.fi/problemset/task/1083
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n - 1);
  int ans = -1;

  for (int i = 0; i < n && ans == -1; i++)
    if (a[i] != i + 1)
      ans = i + 1;
  cout << ans;
}
