// semenInRussia, 2024

#include <algorithm>
using namespace std;

#include <array>
#include <iostream>

#define MAX(a, b) (a > b ? a : b)
#define ABS(a, b) (a > b ? a - b : b - a)

struct point {
  size_t x;
  size_t y;
};

inline size_t dist(point a, point b) { return ABS(a.x, b.x) + ABS(a.y, b.y); }

inline point move_h(point p, size_t w, size_t h) {
  return {p.x + w, h - p.y + 1};
}

inline point move_v(point p, size_t w, size_t h) {
  return {w - p.x + 1, p.y + h};
}

int main() {
  size_t w, h;
  cin >> w >> h;

  size_t x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  point a = {x1, y1};
  point b = {x2, y2};

  array<size_t, 8> dists = {
      dist(a, b),
      dist(move_v(a, w, h), b),
      dist(move_h(a, w, h), b),
      dist(a, move_v(b, w, h)),
      dist(a, move_h(b, w, h)),
      dist(move_h(a, w, h), move_v(b, w, h)),
      dist(move_h(a, w, h), move_h(b, w, h)),
      dist(move_v(a, w, h), move_v(b, w, h)),
  };

  cout << *min_element(dists.begin(), dists.end()) << endl;

  return 0;
}
