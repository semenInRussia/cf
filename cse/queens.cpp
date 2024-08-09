// semenInRussia 2024
// https://cses.fi/problemset/task/1624
#include <iostream>
using namespace std;
using ll = long long;

const int N = 8;
string t[N]; // field
bool row[N], col[N];
bool diagl[4 * N], diagr[4 * N];

int dl[N][N], dr[N][N];

void use(int i, int j, int v) {
  col[j] = row[i] = diagr[dr[i][j]] = diagl[dl[i][j]] = v;
}

// used rows, columns, diagonales
ll f(int i, int j, int n) {
  if (row[i] || col[j] || diagl[dl[i][j]] || diagr[dr[i][j]] || t[i][j] == '*')
    return 0;

  if (n == 8)
    return 1;

  use(i, j, 1);
  ll ans = 0;
  for (int A = 0; A < N; A++) {
    if (row[A])
      continue;
    for (int B = j + 1; B < N; B++)
      ans += f(A, B, n + 1);
  }
  use(i, j, 0);

  return ans;
}

int main() {
  // dl
  int i = 0;
  int num = 0;
  for (int j = 0; j < N; j++) {
    for (int k = 0; j + k < N && i + k < N; k++)
      dl[i + k][j + k] = num;
    num++;
  }
  for (int j = 0; j < N; j++) {
    for (int k = 0; j + k < N && i + k < N; k++)
      dl[j + k][i + k] = num;
    num++;
  }

  // dr
  num = 0;
  i = N - 1;
  for (int j = 0; j < N; j++) {
    for (int k = 0; i - k >= 0 && j + k < N; k++)
      dr[i - k][j + k] = num;
    num++;
  }
  i = 0;
  for (int j = 0; j < N; j++) {
    for (int k = 0; j - k >= 0 && i + k < N; k++)
      dr[j - k][i + k] = num;
    num++;
  }

  for (int i = 0; i < N; i++)
    cin >> t[i];
  ll ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      ans += f(i, j, 1);
  cout << ans;
}
