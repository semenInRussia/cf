// Copyright 2024 semenInRussia

// strategy:

// d[i][j] = t[i][j] == t[0][0] || (d[i][j-1] && d[i-1][j])

#include <iostream>
using namespace std;

const int maxw = 500;
int d[maxw][maxw];
string t[maxw];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> t[i];

    for (int i = 0; i < n; i++)
      d[i][0] = t[0][0] == t[i][0];
    for (int i = 0; i < m; i++)
      d[0][i] = t[0][0] == t[0][i];

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        int cur = t[i][j];
        d[i][j] = (t[i - 1][j] == cur && d[i - 1][j]) ||
                  (t[i][j - 1] == cur && d[i][j - 1]);
      }
    }

    cout << (d[n - 1][m - 1] ? "YES\n" : "NO\n");
  }
}
