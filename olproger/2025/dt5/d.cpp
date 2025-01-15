// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct point {
  int64_t x, y;
};

bool operator<(point a, point b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

int64_t inf = 1e18;
pair<point, point> INF{{-inf, -inf}, {inf, inf}};

set<pair<point, point>> del;

int64_t dist(pair<point, point> a) {
  if (del.count(a)) {
    return inf;
  }
  int64_t d1 = a.first.x - a.second.x;
  int64_t d2 = a.first.y - a.second.y;
  return abs(d1) + abs(d2);
}

pair<point, point> get_closest_points(pair<point, point> a,
                                      pair<point, point> b) {
  return dist(a) < dist(b) ? a : b;
}

pair<point, point> strip_solve(vector<point> &p) {
  pair<point, point> ans = INF;
  for (int i = 0; i < (int)p.size(); i++) {
    for (int j = i + 1; j < (int)p.size() && j - i < 9; j++) {
      ans = get_closest_points(ans, {p[i], p[j]});
    }
  }
  return ans;
}

pair<point, point> solve(vector<point> &points, int l, int r) {
  if (l == r) {
    return INF;
  }
  int mid = (l + r) / 2;

  pair<point, point> ansl = solve(points, l, mid);
  pair<point, point> ansr = solve(points, mid + 1, r);
  pair<point, point> ans;

  ans = get_closest_points(ansl, ansr);
  int64_t delta = dist(ans);

  point mid_point = points[mid];
  vector<point> strip;
  for (int i = l; i < r; i++) {
    if (abs(points[i].x - mid_point.x) <= delta) {
      strip.push_back(points[i]);
    }
  }
  sort(strip.begin(), strip.end(),
       [](point a, point b) { return a.y < b.y || (a.y == b.y && a.x < b.x); });
  return get_closest_points(ans, strip_solve(strip));
}

void solvey(vector<point> &v, int n, int k) {
  vector<int> a;
  for (auto p : v) {
    a.push_back(p.x);
  }

  sort(a.begin(), a.end());

  set<pair<int, pair<int, int>>> s;

  for (int i = 0; i + 1 < n; i++) {
    s.insert({abs(a[i] - a[i + 1]), {i, i + 1}});
  }

  while (k--) {
    auto it = s.begin();
    auto [dx, ij] = *it;
    s.erase(it);
    cout << dx << "\n";

    auto [i, j] = ij;

    if (j + 1 == n) {
      continue;
    }

    s.insert({abs(a[i] - a[j + 1]), {i, j + 1}});
  }
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<point> v(n);

  int64_t mny = +inf;
  int64_t mxy = -inf;

  for (auto &p : v) {
    cin >> p.x >> p.y;
    mny = min(p.y, mny);
    mxy = max(p.y, mxy);
  }

  if (mny == mxy) {
    solvey(v, n, k);
    return;
  }

  if (n <= 1000) {
    multiset<int64_t> s;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        s.insert(dist({v[i], v[j]}));
      }
    }

    for (auto x : s) {
      if (k <= 0) {
        break;
      }
      cout << x << "\n";
      k--;
    }
    return;
  }

  for (int j = 0; j < k; j++) {
    sort(v.begin(), v.end());
    auto [a, b] = solve(v, 0, v.size());
    cout << dist({a, b}) << "\n";
    del.insert({a, b});
    del.insert({b, a});
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n";
  }
}
