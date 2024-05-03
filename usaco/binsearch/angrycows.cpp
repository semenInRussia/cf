// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9 + 7;

using namespace std;

const int maxn = 5e4;
int x[maxn], n;

ifstream cin("angry.in");
ofstream cout("angry.out");

bool check(int i, int r) {
  int curr = r;
  int i = 0, j = 1;
  while (i < n) {
    while (j + 1 < n && x[j + 1] - x[j] >= curr)
      j++;
    curr--;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x, x + n);

  // for every i:
  int ans = inf;
  for (int i = 0; i < n; i++) {
    int l = 0, r = inf;
    // first m: check(i, m) = 1
    while (r > l + 1) {
      int m = (r - l) / 2 + l;
      if (check(i, m)) {
        cout << i << ' ' << m << '\n';
        r = m;
      } else
        l = m;
    }
    if (r == inf)
      continue;
    else
      ans = min(ans, r);
  }
  ifstream cin("angry.in");
  ofstream cout("angry.out");
  cout << ans << endl;
}
