// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;
int b[N][N], a[N][N];

struct rect {
  int x0;
  int y0;
  int x1;
  int y1;
};

int main() {
  int n, m;
  cin >> n >> m;

  int r, c;
  cin >> r >> c;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i + 1][j + 1] = b[i][j + 1] + b[i + 1][j] - b[i][j] + a[i][j];
    }
  }

  vector<pair<rect, int64_t>> v(n * m * 2);

  for (int z : {1, 2}) {
    (void)z;
    swap(r, c);
    for (int i = 0; i + r <= n; i++) {
      for (int j = 0; j + c <= m; j++) {
        int64_t s = b[i + r][j + c] - b[i][j + c] - b[i + r][j] + b[i][j];
        v.push_back({{i, j, i + r, j + c}, s});
      }
    }
  }

  for (auto [r1, s1] :)
}
