// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a;
vector<int> col, row;
void solve() {
  int n, m;
  cin >> n >> m;
  a.clear();
  a.resize(n);
  for (auto &row : a)
    row.resize(m);
  col.resize(m * n);
  row.resize(m * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int el;
      cin >> el;
      el--;
      col[el] = j, row[el] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int el;
      cin >> el;
      el--;
      a[i][j] = el;
    }
  }

  int ans = true;
  // rows
  for (int i = 0; i < n; i++) {
    int exp = row[a[i][0]];
    for (int j = 0; j < m; j++)
      if (row[a[i][j]] != exp)
        ans = false;
  }

  // cols
  for (int j = 0; j < m; j++) {
    int exp = col[a[0][j]];
    for (int i = 0; i < n; i++)
      if (col[a[i][j]] != exp)
        ans = false;
  }

  cout << (ans ? "YES\n" : "NO\n");
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
