// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3, inf = 1e9;
int f[N], p[N];

int main() {
  freopen("input.txt", "r", stdin);
#ifdef ONLINE_JUDGE
  freopen("output.txt", "w", stdout);
#endif
  // --
  int n;
  cin >> n;
  p[0] = -1;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = +inf;
    for (int d : {1, 5, 6})
      if (i - d >= 0 && f[i - d] + 1 < f[i])
        f[i] = f[i - d] + 1, p[i] = i - d;
    if (f[i] == +inf)
      f[i] = -1, p[i] = -1;
  }

  vector<int> path;
  int i = n;
  while (i != 0) {
    path.push_back(i - p[i]);
    i = p[i];
  }
  sort(path.begin(), path.end());
  cout << path.size() << "\n";
  for (auto i : path)
    cout << i << ' ';
}
