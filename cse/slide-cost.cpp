// semenInRussia 2024
// https://cses.fi/problemset/task/1077
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5;
int a[N], b[N], id[N], t[N + 100], k, u, n;
ll sum, s[N + 100];

// NOTE: that R is index of number in b[]
int lower(int r) { // count elements lower than R
  int ans = 0;
  for (; r > 0; r -= r & -r)
    ans += t[r];
  return ans;
}

ll lower_sum(int r) { // sum of all elements which is greater than R
  ll ans = 0;
  for (; r > 0; r -= r & -r)
    ans += s[r];
  return ans;
}

void add(int i, int v) { // v is either {-1,+1} delete/add
  int x = b[i - 1];
  for (; i <= N; i += i & -i) {
    t[i] += v;     // count amount
    s[i] += x * v; // sum
  }
  sum += x * v;
}

int medi() {          // return index in b[] which is median of current window
  int l = -1, r = u;  // indexes in b[]
  while (r - l > 1) { // find fist i: low >= k - low (low = qry(i + 1))
    int m = (r + l) / 2;
    int lw = lower(m + 1);
    if (lw >= k - lw)
      r = m;
    else
      l = m;
  }
  return r;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sum = 0;
  sort(b, b + n);
  u = unique(b, b + n) - b;

  for (int i = 0; i < n; i++) {
    id[i] = lower_bound(b, b + u, a[i]) - b;
  }

  for (int i = 0; i < k; i++) {
    int j = id[i];
    add(j + 1, +1);
  }

  for (int i = 0; i + k <= n; i++) {
    // find answer for [i; i+k)
    int m = medi();
    int lw = lower(m + 1); // <=
    ll sm = lower_sum(m + 1);
    ll ans = (1ll * lw * b[m] - sm) + ((sum - sm) - 1ll * (k - lw) * b[m]);

    // display it
    cout << ans << '\n';

    // move sliding window rightwards
    int j = id[i];
    add(j + 1, -1);
    if (i + k < n)
      add(id[i + k] + 1, 1);
  }
}
