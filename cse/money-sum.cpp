// semenInRussia 2024
// https://cses.fi/problemset/task/1745
#include <iostream>
using namespace std;

const int X = 1e5 + 100, N = 100;
bool f[X];
int c[N];

int main() {
  int n;
  cin >> n;
  int S = 1;
  for (int i = 0; i < n; i++)
    cin >> c[i], S += c[i];

  f[0] = 1;
  for (int i = 0; i < n; i++)
    for (int s = S; s >= c[i]; s--)
      f[s] |= f[s - c[i]];

  int cnt = 0;
  for (int s = 1; s <= S; s++)
    cnt += f[s];
  cout << cnt << '\n';
  for (int s = 1; s <= S; s++)
    if (f[s])
      cout << s << ' ';
}
