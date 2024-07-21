// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int M = 300'000, inf = 1e9;
vector<int> vars;
int f[M]; // f[i] is minimum pyramids which can be done with i cores
int main() {
  vars.push_back(1);
  for (int n = 2; vars.back() < M; n++)
    vars.push_back(vars.back() + (1 + n) * n / 2);
  f[0] = 0, f[1] = 1;
  for (int i = 2; i <= M; i++) {
    f[i] = +inf;
    for (int k = 0; k < (int)vars.size() && vars[k] <= i; k++)
      if (f[i - vars[k]] || i == vars[k])
        f[i] = min(f[i], 1 + f[i - vars[k]]);
  }
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    cout << f[m] << '\n';
  }
}
