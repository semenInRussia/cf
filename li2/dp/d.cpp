// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 35;
int stop[N], f[N];
int main() {
  int n, k;
  cin >> n >> k;
  int l;
  cin >> l;
  for (int i = 0; i < l; i++) {
    int s;
    cin >> s;
    stop[s - 1] = 1;
  }
  f[0] = 1;
  for (int i = 1; i < n; i++) {
    if (stop[i])
      continue;
    for (int d = 1; d <= k; d++)
      if (i - d >= 0)
        f[i] += f[i - d];
  }
  cout << f[n - 1];
}
