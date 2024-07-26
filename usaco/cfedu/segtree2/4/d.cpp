// semenInRussia 2024
#pragma GCC optimize("Ofast,unroll-loops")
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct query {
  int l, r, idx;
};
bool operator<(query a, query b) { return a.r < b.r; }

const int N = 2e5, C = 448, A = 1e6 + 100;
int a[N], cnt[A];
ll answers[N];
vector<query> b[N / C + 1];

ll ans = 0;
vector<int> els;
bool used[A];
void add(int i) {
  int s = a[i];
  if (!used[s]) {
    els.push_back(s);
    used[s] = true;
  }

  int ks = cnt[s];
  ans -= 1ll * ks * ks * s;
  cnt[s]++;
  ks++;
  ans += 1ll * ks * ks * s;
}

void rem(int i) {
  int s = a[i];
  int ks = cnt[s];
  ans -= 1ll * ks * ks * s;
  cnt[s]--;
  ks--;
  ans += 1ll * ks * ks * s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < t; i++) {
    query q;
    cin >> q.l >> q.r;
    q.l--;
    q.idx = i;
    b[q.l / C].push_back(q);
  }
  for (int g = 0; g * C <= n; g++) {
    if (b[g].empty())
      continue;
    sort(b[g].begin(), b[g].end());
    ans = 0;
    int l = b[g][0].l, r = b[g][0].r;
    for (int i = l; i < r; i++)
      add(i);
    for (auto q : b[g]) {
      while (l > q.l)
        add(--l);
      while (l < q.l)
        rem(l++);
      while (r < q.r)
        add(r++);
      answers[q.idx] = ans;
    }
    for (auto s : els)
      used[s] = cnt[s] = 0;
    els.clear();
  }
  for (int i = 0; i < t; i++)
    cout << answers[i] << '\n';
}
