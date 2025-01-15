// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int n, m;

const int N = 2005;
int d[N][N], h[N][N], a[N][N], b[N][N];

// bool check(int li, int lj, int ri, int rj) {
//   vector<string> s;
//   for (int i = li; i < ri; i++) {
//     for (int j = lj; j < rj; j++) {
//       s.push_back();
//     }
//   }
// }

int H(int i, int j) {
  if (min(i, j) == -1) {
    return 0;
  }
  if (j == m || i == n) {
    return h[i + 1][j - 1];
  }
  return h[i][j];
}

int D(int i, int j) {
  if (min(i, j) == -1) {
    return 0;
  }
  if (j == m || i == n) {
    return d[i - 1][j - 1];
  }
  return d[i][j];
}

int qry(int li, int lj, int ri, int rj) {
  return -b[li][rj] - b[ri][lj] + b[ri][rj] + b[li][lj];
}

bool check(int i, int j, int r) {
  if (i + r > n || j + r > m) {
    return false;
  }
  auto d1 = D(i + r - 1, j + r - 1) - D(i - 1, j - 1);
  auto d2 = H(i, j + r - 1) - H(i + r, j - 1);
  auto s = qry(i, j, i + r, j + r);
  return d1 == r && d2 == r && s == r * 2 - (r % 2);
};

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] == '#';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i + 1][j + 1] = b[i][j + 1] + b[i + 1][j] - b[i][j] + a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0) {
        d[i][j] = a[i][j];
      } else {
        d[i][j] = d[i - 1][j - 1] + a[i][j];
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i == n - 1 || j == 0) {
        h[i][j] = a[i][j];
      } else {
        h[i][j] = h[i + 1][j - 1] + a[i][j];
      }
    }
  }

  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int r = 2; r <= max(n, m); r++) {
        if (!a[i][j]) {
          break;
        }

        bool ok = check(i, j, r);
        ans += ok;

        auto d1 = D(i + r - 1, j + r - 1) - D(i - 1, j - 1);

        if (ok || d1 < r) {
          // cout << i << " " << j << ": " << r << '\n';
          break;
        }
      }
    }
  }

  cout << ans;
}
