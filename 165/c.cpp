// Copyright 2024 semenInRussia

#include <iostream>
#include <numeric>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9;

const int maxn = 3e5;
int a[maxn];

struct thr {
  int dif, i, id;
};

bool operator<(thr x, thr y) {
  if (x.dif != y.dif)
    return x.dif < y.dif;
  else if (x.i != y.i)
    return a[x.i] > a[y.i];
  else
    return x.id < y.id;
};

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n == 1) {
    cout << a[0] << '\n';
    return;
  }

  multiset<thr> q;
  int t = 0;
  q.insert({a[0] - a[1], 0, t});
  q.insert({a[n - 1] - a[n - 2], n - 1, t});

  for (int i = 1; i < n - 1; i++) {
    t++;
    q.insert({a[i] - a[i - 1], i, t});
    q.insert({a[i] - a[i + 1], i, t});
  }

  int ans = accumulate(a, a + n, 0);
  set<int> rem;

  for (int z = 0; z < k; z++) {
    if (q.empty())
      break;
    while (rem.count(q.rbegin()->id))
      q.erase(q.find(*q.rbegin()));
    thr top = *q.rbegin();
    int i = top.i, dif = top.dif;
    if (dif < 0)
      break;
    rem.insert(top.id), t++;
    ans -= dif, a[i] -= dif;
    if (i > 0)
      q.insert({a[i] - a[i - 1], i, t});
    if (i < n - 1)
      q.insert({a[i] - a[i + 1], i, t});
  }

  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
