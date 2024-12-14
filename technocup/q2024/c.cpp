// semenInRussia 2024
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int w, h, b;

#define MAX(a, b) (a > b ? a : b)
#define ABS(a, b) (a > b ? a - b : b - a)

struct point {
  int x;
  int y;
};

inline ll dist(point a, point b) { return ABS(a.x, b.x) + ABS(a.y, b.y); }

inline point move_h(point p) {
  int d = h - p.x;
  return {-d, p.y};
}
inline point move_v(point p) {
  int d = w - p.y;
  return {p.x, -d};
}

ll dist2(point a, point b) {
  auto dx = abs(a.x - b.x);
  auto dy = abs(a.y - b.y);
  dx = min(dx, h - dx);
  dy = min(dy, w - dy);
  return dx + dy;
}

ll imp(pair<point, int> a, point b) {
  return max(0ll, a.second - dist2(b, a.first));
}

const int N = 110;
pair<point, int> seed[N];

ll d[N][N];

int main() {
  cin >> w >> h >> b;
  for (int i = 0; i < b; i++) {
    cin >> seed[i].first.y >> seed[i].first.x >> seed[i].second;
  }

  const ll inf = 1e18 + 5;

  vector<string> ans;
  ans.resize(h);

  for (int i = 0; i < h; i++) {
    ans[i].resize(w);
    for (int j = 0; j < w; j++) {
      ll bst = 0;
      ans[i][j] = '#';
      for (int k = 0; k < b; k++) {
        point a = {i, j};
        auto op = imp(seed[k], a);
        if (op > bst) {
          bst = op;
          ans[i][j] = k + 'a';
        } else if (op == bst) {
          ans[i][j] = '#';
        }
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (ans[i][j] == '#') {
        d[i][j] = 0;
      } else {
        int k = ans[i][j] - 'a';
        point a = {i, j};
        d[i][j] = imp(seed[k], a);
      }
    }
  }

  for (auto row : ans) {
    cout << row << "\n";
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << d[i][j] << " \n"[j == w - 1];
    }
  }
}
