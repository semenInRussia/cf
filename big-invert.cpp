// Copyright 2024 semenInRussia
#include <bitset>
#include <iostream>
using namespace std;

const int maxn = 5005;
int n, invs[maxn];
bitset<maxn> b;

bool check(int k) {
  fill(invs, invs + n, 0);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    tot += invs[i];
    bool cur = b[i];
    if (tot & 1)
      cur ^= 1;
    if (cur == 0 && i + k > n)
      return false;
    if (cur == 0)
      invs[i + k]--, tot++;
  }
  return true;
}

void solve() {
  string s;
  cin >> n >> s;
  b.reset();
  for (int i = 0; i < n; i++)
    b[i] = s[i] - '0';

  int ans = -1;
  for (int i = n; i >= 1; i--) {
    if (check(i)) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
