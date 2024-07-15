// semenInRussia 2024
#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
const int N = 600;
int a[N][N], ty[N][N], b[N][N];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      ty[i][j] = s[j] - '0';
  }
  // b[i,j] = sum of rectangle with [0,0] x (i,j)
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      b[i + 1][j + 1] = ty[i][j] + b[i + 1][j] + b[i][j + 1] - b[i][j];
  ll A = 0, B = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (ty[i][j])
        A += a[i][j];
      else
        B += a[i][j];
  ll G = 0;
  for (int i = 0; i + k <= n; i++) {
    for (int j = 0; j + k <= m; j++) {
      ll x = b[i + k][j + k] + b[i][j] - b[i + k][j] - b[i][j + k];
      x = x - (k * k - x);
      if (G)
        G = gcd(G, x);
      else
        G = x;
    }
  }
  if ((G && (A - B) % G == 0) || A == B)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
