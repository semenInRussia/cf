// semenInRussia 2024
// https://cses.fi/problemset/task/1076
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N], b[N], id[N], t[N + 100], k, u, n;

int qry(int r) {
  int ans = 0;
  for (; r > 0; r -= r & -r)
    ans += t[r];
  return ans;
}

void add(int i, int v) {
  for (; i <= N; i += i & -i)
    t[i] += v;
}

int medi() {
  int l = -1, r = u;  // indexes in b[]
  while (r - l > 1) { // find last: low > k - low (low = qry(i + 1))
    int m = (r + l) / 2;
    // 2 3 4 5
    int lw = qry(m + 1);
    if (lw >= k - lw)
      r = m;
    else
      l = m;
  }
  return b[r];
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  u = unique(b, b + n) - b;

  for (int i = 0; i < n; i++) {
    id[i] = lower_bound(b, b + u, a[i]) - b;
  }

  for (int i = 0; i < k; i++) {
    int j = id[i];
    add(j + 1, 1);
  }

  for (int i = 0; i + k <= n; i++) {
    // find median for [i; i+k)
    cout << medi() << ' ';
    int j = id[i];
    add(j + 1, -1);
    if (i + k < n)
      add(id[i + k] + 1, 1);
  }
}
