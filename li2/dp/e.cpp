// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4, inf = 1e9;
int a[N], f[N], p[N];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n - 1; i++)
    cin >> a[i];
  fill(f, f + n, -inf);
  p[0] = -1;
  f[0] = 0;
  for (int i = 1; i < n; i++)
    for (int d = 1; d <= k; d++)
      if (i - d >= 0 && f[i - d] + a[i] >= f[i])
        f[i] = f[i - d] + a[i], p[i] = i - d;

  vector<int> path;
  int i = n - 1;
  while (i != -1) {
    path.push_back(i + 1);
    i = p[i];
  }
  reverse(path.begin(), path.end());
  cout << f[n - 1] << '\n';
  cout << path.size() - 1 << "\n";
  for (int i : path)
    cout << i << ' ';
}
