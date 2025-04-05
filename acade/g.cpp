#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct point {
  int x, y;
};

long long operator^(point a, point b) {
  return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

point abs(point p) {
  if (p.y < 0) {
    return {-p.x, -p.y};
  }
  if (p.y == 0) {
    return {abs(p.x), p.y};
  }
  return p;
}

point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }

void solve(int n) {
  vector<point> p(2 * n);
  for (int i = 0; i < n; i++) {
    int x0, x1, y;
    cin >> x0 >> x1 >> y;
    p[2 * i] = {x0, y};
    p[2 * i + 1] = {x1, y};
  }

  long long ans = 0;

  for (int i = 0; i < 2 * n; i++) {
    point p1 = p[i];

    auto cmp = [&](pair<point, int> x, pair<point, int> y) {
      auto l = abs(x.first - p1) ^ abs(y.first - p1);
      if (l == 0) {
        return x.second > y.second;
      }
      return l > 0;
    };

    vector<pair<point, int>> a;

    for (int j = 0; j < n; j++) {
      if (p[2 * j].y == p1.y) {
        continue;
      }
      auto s = p[2 * j];
      auto t = p[2 * j + 1];
      int len = abs(s.x - t.x);
      if (cmp({s, 0}, {t, 0})) {
        a.push_back({s, len});
        a.push_back({t, -len});
      } else {
        a.push_back({s, -len});
        a.push_back({t, +len});
      }
    }

    sort(a.begin(), a.end(), cmp);

    long long pref = abs(p[i].x - p[i ^ 1].x); // only current segment
    ans = max(ans, pref);
    for (auto [d, v] : a) {
      pref += v;
      ans = max(ans, pref);
    }
  }
  cout << ans << "\n";
}

int main() {
  int n;
  while (cin >> n) {
    solve(n);
  }
}
