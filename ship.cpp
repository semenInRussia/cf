// Copyright 2024 semenInRussia

#include <iostream>

using ll = long long;
const ll inf = (ll)1e22;

using namespace std;

const string DIRS = "UDLR";
const ll dxs[4] = {0, 0, -1, +1}, dys[4] = {+1, -1, 0, 0};

ll x0, yc0, x2, y2, n;
string s;

bool check(ll m) {
  ll x = x0, y = yc0;
  for (int i = 0; i < n; i++) {
    int ind = DIRS.find(s[i]);
    ll k = m / n;
    bool o = i < (m % n);
    x += k * dxs[ind], y += k * dys[ind];
    x += o * dxs[ind], y += o * dys[ind];
  }

  ll need = abs(x2 - x) + abs(y2 - y);
  return need <= m;
}

int main() {
  cin >> x0 >> yc0 >> x2 >> y2 >> n >> s;

  ll l = 0, r = inf;
  while (r > l + 1) {
    ll m = (r - l) / 2 + l;
    if (check(m))
      r = m;
    else
      l = m;
  }

  cout << (check(r) ? r : -1);
}
