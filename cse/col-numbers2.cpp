// semenInRussia 2024
// https://cses.fi/problemset/task/2216
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 100;
int a[N], o[N], o2[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    o[i] = i;
  }
  sort(o, o + n, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 0; i < n; i++)
    o2[i] = o[i];

  int ans = 1;
  for (int i = 1; i < n; i++)
    if (o[i - 1] > o[i])
      ans++;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    o2[a[x]] = y;
    o2[a[y]] = x;

    //
    set<int> s = {a[x] + 1, a[x], a[y] + 1, a[y]};
    for (int x : s) {
      if (x <= 0 || x >= n)
        continue;
      if ((o[x - 1] > o[x]) && (o2[x - 1] < o2[x]))
        ans--;
      if ((o[x - 1] < o[x]) && (o2[x - 1] > o2[x]))
        ans++;
    }
    //

    o[a[x]] = y;
    o[a[y]] = x;

    swap(a[x], a[y]);
    cout << ans << '\n';
  }
}
