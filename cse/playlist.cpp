// semenInRussia 2024
// https://cses.fi/problemset/task/1141
#include <iostream>
#include <set>
using namespace std;

const int N = 2e5;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  multiset<int> s;
  int r = 0, ans = 1;
  for (int l = 0; l < n;) {
    while (r < n && s.count(a[r]) < 1)
      s.insert(a[r++]);
    ans = max(ans, r - l);
    if (r == n)
      break;
    // move l, while find thing where count=2
    while (l < n && a[l] != a[r])
      s.erase(s.find(a[l++]));
    s.erase(s.find(a[l++]));
  }
  cout << ans;
}
