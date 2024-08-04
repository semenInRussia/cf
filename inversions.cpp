// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 100;
int t[maxn], a[maxn], b[maxn];
int qry(int r) {
  int res = 0;
  for (; r > 0; r -= r & -r)
    res += t[r];
  return res;
}

void add(int k, int v) {
  for (; k <= maxn; k += k & -k)
    t[k] += v;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], b[i] = a[i];
  sort(b, b + n);
  using ll = long long;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int id = lower_bound(b, b + n, a[i]) - b;
    // count which is more at left.
    ans += i - qry(id + 1);
    add(id + 1, 1);
  }
  cout << ans;
}
