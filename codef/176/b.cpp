// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC target("avx2")

const int inf = 1e9 + 5;

using namespace std;

struct st {
  int k;

  priority_queue<int, vector<int>, greater<int>> s;
  int64_t sum = 0;

  st(int _k) : k(_k) {}

  void insert(int x) {
    if ((int)s.size() < k - 1) {
      s.push(x);
      sum += x;
      return;
    }
    auto it = s.top();
    if (x > it) {
      sum -= it;
      s.pop();
      sum += x;
      s.push(x);
    }
  }

  int64_t qry() {
    // get top k-2
    auto ans = sum;
    if ((int)s.size() == k - 1) {
      ans -= s.top();
    }
    return ans;
  }

  int64_t other() {
    if ((int)s.size() < k - 1) {
      return 0;
    }
    return s.top();
  }

  bool ok() { return (int)s.size() >= k - 2; }
};

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  if (k == 1) {
    int oth = 0;
    for (int i = 1; i < n - 1; i++) {
      oth = max(oth, a[i]);
    }
    int ans = max(a[0] + a[n - 1], max(a[n - 1], a[0]) + oth);
    cout << ans << "\n";
    return;
  }

  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    st q(k);
    for (int j = i + 1; j < n; j++) {
      if (q.ok()) {
        int64_t other = 0;
        if (i != 0) {
          other = max(other, (int64_t)a[0]);
        }
        if (j != n - 1) {
          other = max(other, (int64_t)a[n - 1]);
        }
        other = max(other, q.other());
        ans = max(ans, q.qry() + other + a[i] + a[j]);
      }
      q.insert(a[j]);
    }
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
