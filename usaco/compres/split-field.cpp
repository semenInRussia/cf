// Copyright 2024 semenInRussia

#include <algorithm>
#include <climits>
#include <cstdint>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long;
const ll inf = LLONG_MAX;

inline ll area(ll a, ll b) { return 1LL * a * b; }

int main() {
  ifstream cin("split.in");
  ofstream cout("split.out");
  int n;
  cin >> n;

  vector<pair<ll, ll>> ps(n);
  for (auto &p : ps)
    cin >> p.first >> p.second;

  ll ans = inf, ar;
  for (int _z : {1, 2}) {
    sort(ps.begin(), ps.end());

    // prefix and suffix maximum and minimum
    vector<ll> smx(n), smn(n), pmx(n), pmn(n);

    // suffix maximum/minimum
    ll mx = -inf, mn = inf;
    for (int i = n - 1; i >= 0; i--) {
      mx = max(mx, ps[i].second), mn = min(mn, ps[i].second);
      smx[i] = mx, smn[i] = mn;
    }

    // prefix maximum/minimum
    mx = -inf, mn = inf;
    for (int i = 0; i < n; i++) {
      mx = max(mx, ps[i].second), mn = min(mn, ps[i].second);
      pmx[i] = mx, pmn[i] = mn;
    }

    // also check if only one area
    ll s = area(ps[n - 1].first - ps[0].first, pmx[n - 1] - pmn[n - 1]);
    ans = min(ans, s);

    for (int i = 1; i + 1 < n; i++) {
      if (ps[i].first == ps[i + 1].first)
        continue;
      ll a = area(pmx[i] - pmn[i],            //
                  ps[i].first - ps[0].first); //
      ll b = area(smx[i + 1] - smn[i + 1],    // right
                  ps[n - 1].first - ps[i + 1].first);
      ans = min(ans, a + b);
    }

    ar = area(pmx.back() - pmn.back(), ps.back().first - ps.front().first);

    // change axis
    for (auto &p : ps)
      swap(p.first, p.second);
  }

  cout << (ar - ans) << endl;
}
