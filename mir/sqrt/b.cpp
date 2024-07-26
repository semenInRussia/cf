// semenInRussia 2024
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

#pragma GCC optimize("unroll-loops,Ofast")
using namespace std;
const int N = 1e5 + 100, K = 315;
int a[N], answers[N], cnt[N];
struct query {
  int l, r, idx;
};
vector<query> b[(N / K) + 1];

int ans = 0;
void add(int i) {
  if (a[i] >= N)
    return;
  if (cnt[a[i]] == a[i])
    ans--;
  cnt[a[i]]++;
  if (cnt[a[i]] == a[i])
    ans++;
}
void rem(int i) {
  if (a[i] >= N)
    return;
  if (cnt[a[i]] == a[i])
    ans--;
  cnt[a[i]]--;
  if (cnt[a[i]] == a[i])
    ans++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++) {
    query q;
    cin >> q.l >> q.r;
    q.l--;
    q.idx = i;
    b[q.l / K].push_back(q);
  }
  int mx = 1;
  for (int i = 0; i < n; i++)
    if (a[i] <= n)
      mx = max(mx, a[i]);

  for (int g = 0; g * K <= n; g++) {
    sort(b[g].begin(), b[g].end(), [](auto a, auto b) { return a.r < b.r; });
    if (b[g].empty())
      continue;
    fill(cnt, cnt + mx + 1, 0);
    ans = 0;
    int l = b[g][0].l, r = b[g][0].r;
    for (int i = l; i < r; i++)
      add(i);
    for (auto q : b[g]) {
      while (l < q.l)
        rem(l++);
      while (l > q.l)
        add(--l);
      while (r < q.r)
        add(r++);
      answers[q.idx] = ans;
    }
  }
  for (int i = 0; i < m; i++)
    cout << answers[i] << '\n';
}
