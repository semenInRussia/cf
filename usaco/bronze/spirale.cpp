// Copyright 2024 semenInRussia

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int m, n, k;
int f[50][50]; // f - field

int s[50][50]; // s is a temporary field for add_spiral function
void add_spiral(int y0, int x0, int t) {
  // here 3D array: 1st dimension - type of spiral, 2nd - direction
  // number, 3th - axis
  int d[2][4][2] = {{{-1, 0}, {0, +1}, {+1, 0}, {0, -1}},
                    {{-1, 0}, {0, -1}, {+1, 0}, {0, +1}}};
  s[y0][x0] = 1;
  int i = 2, cnt = 1;
  int width = 0, usew = 0;
  int dt = 0;
  int x = x0, y = y0; // the first step is up, so move down before
  while (cnt < m * n) {
    width += (0 == (usew & 1));
    usew++;
    for (int j = 0; j < width; j++) {
      y += d[t][dt][0], x += d[t][dt][1];
      bool ok = x >= 0 && x < m && y >= 0 && y < n;
      if (ok)
        s[y][x] = i, cnt++;
      i++;
    }
    dt = (dt + 1) % 4;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      f[i][j] = min(f[i][j], s[i][j]);
}

int main() {
  cin >> n >> m >> k;

  // fill f with +INF, because on it will after be applied min
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      f[i][j] = INT32_MAX;

  for (int i = 0; i < k; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    add_spiral(x - 1, y - 1, t);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << f[i][j] << ' ';
    cout << '\n';
  }
}
