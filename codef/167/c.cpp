// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 3e5;
int a[maxn], b[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  int A = 0, B = 0;
  int o = 0, m = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i])
      A += a[i];
    else if (b[i] > a[i])
      B += b[i];
    else if (a[i] == 1)
      o++;
    else if (a[i] == -1)
      m++;
  }
  while (o--) {
    if (A > B)
      B++;
    else
      A++;
  }
  while (m--) {
    if (A > B)
      A--;
    else
      B--;
  }
  cout << min(A, B) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
