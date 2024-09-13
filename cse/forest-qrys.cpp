// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 1005;
int a[N][N], b[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j] == '*';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i + 1][j + 1] = b[i + 1][j] + b[i][j + 1] - b[i][j] + a[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--, j1--;
    int x = b[i2][j2] - b[i2][j1] - b[i1][j2] + b[i1][j1];
    cout << x << '\n';
  }
}
