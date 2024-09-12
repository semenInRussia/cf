// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll inf = (ll)1e19;

const int maxn = 2e5 + 1;
ll p[maxn], a[maxn], mxscore[maxn];
bool used[maxn];

int n;

bool check(ll m, int pos, int k) {
  int start = pos;
  ll score = 0;
  fill(used, used + n, 0);
  while (!used[pos] && k) {
    if (a[pos] * k >= m - score * 1ll)
      return true;
    used[pos] = 1;
    score += a[pos];
    pos = p[pos];
    k--;
  }

  return false;
}

void solve() {
  int k, p1, p2;
  cin >> n >> k >> p1 >> p2;
  p1--, p2--;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    p[i]--;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int mx = *max_element(a, a + n);
  for (int pos : {p1, p2}) {
    ll l = -1;
    ll r = 1ll * mx * k * 3;
    while (r > l + 1) {
      ll m = (r - l) / 2 + l;
      if (check(m, pos, k))
        l = m;
      else
        r = m;
    }
    mxscore[pos] = l;
  }

  if (mxscore[p1] > mxscore[p2])
    cout << "Bodya\n";
  else if (mxscore[p1] < mxscore[p2])
    cout << "Sasha\n";
  else
    cout << "Draw\n";

  // - binary search
  //   can start from pos and make m in k steps
  //   if k * a[pos] >= m, yes
  //   if no,
  //     change pos to p[pos]
  //     if a[new pos] < a[old pos]
  //     change pos, if greater to step 1

  // - find max
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
