// semenInRussia 2024
// https://cses.fi/problemset/task/2216
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5 + 100;
int a[N], o[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    o[i] = i;
  }
  sort(o, o + n, [](int i, int j) { return a[i] < a[j]; });
  int ans = 1;
  for (int i = 1; i < n; i++)
    if (o[i - 1] > o[i])
      ans++;
  cout << ans;
}
