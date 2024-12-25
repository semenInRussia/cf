#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1005;
int a[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  // try find row

  int s = 0;
  int ans = 0;
  for (int i = 0; i < n && s < 2; i++) {
    // add row
    for (int j = 0; j < m; j++) {
      s += a[i][j];
    }

    if (s == 1) {
      ans = max({ans, (i + 1) * m, n * m - (i + 1) * m});
    }
  }

  s = 0;
  for (int j = 0; j < m && s < 2; j++) {
    // add row
    for (int i = 0; i < n; i++) {
      s += a[i][j];
    }

    if (s == 1) {
      ans = max({ans, (j + 1) * n, n * m - (j + 1) * n});
    }
  }

  cout << ans;
}
