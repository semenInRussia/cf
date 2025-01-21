// semenInRussia 2024
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 104;
const ll B = 1e16;

using bi = pair<ll, ll>;

void operator+=(bi &a, bi b) {
  int64_t y = a.second + b.second;
  int t = y > B;
  if (t) {
    y -= B;
  }
  ll x = a.first + b.first + t;
  a = {x, y};
}

void print(bi x) {
  if (x.first) {
    cout << x.first;
    cout << std::setw(16) << setfill('0') << x.second;
  } else {
    cout << x.second;
  }
}

vector<bi> f[N][N];

int main() {
  int n, k;
  cin >> n >> k;
  // f[i][x][d] - is amount of sequences with length=i, sum=x, maximum=d
  n = 2 * n;
  f[0][0].resize(1);
  f[0][0][0] = bi(0, 1);
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= n; x++) {
      f[i][x].resize(i + 3);
    }
    for (int x = 0; x <= n; x++) {
      for (int c : {-1, +1}) {
        int y = x + c;
        if (y < 0 || y > k) {
          continue;
        }
        for (int p = 0; p <= n; p++) {
          if (p < (int)f[i - 1][x].size() && max(p, y) < (int)f[i][y].size()) {
            f[i][y][max(p, y)] += f[i - 1][x][p];
          }
        }
      }
    }
  }
  print(f[n][0][k]);
}
