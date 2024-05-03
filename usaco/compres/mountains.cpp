// Copyright 2024 semenInRussia

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

bool operator<(Point a, Point b) {
  int v1 = a.x - a.y;
  int v2 = b.x - b.y;
  if (v1 == v2)
    return (a.x + a.y) > (b.x + b.y);
  return v1 < v2;
}

int main() {
  ifstream cin("mountains.in");
  ofstream cout("mountains.out");

  int n;
  cin >> n;

  vector<Point> points(n);

  for (auto &pi : points)
    cin >> pi.x >> pi.y;
  sort(points.begin(), points.end());

  int t = -1, cnt = 0;
  for (auto p : points) {
    int d = p.x + p.y;
    cnt += !(d <= t);
    t = max(t, d);
  }

  cout << cnt << endl;
}
