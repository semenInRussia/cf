// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> a, b;

ll count_greater(ll m) {
  ll cnt = 0;
  for (int ai : a) {
    ll x = 1ll * ((m + ai - 1) / ai);
    cnt += b.size() - (lower_bound(b.begin(), b.end(), x) - b.begin());
  }
  return cnt;
}

int main() {
  int w, h;
  cin >> w >> h;

  int n, m;
  cin >> n >> m;

  ll k;
  cin >> k;

  int prv = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x - prv);
    prv = x;
  }
  a.push_back(w - prv);

  prv = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b.push_back(x - prv);
    prv = x;
  }
  b.push_back(h - prv);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  k--;
  ll l = 0, r = 1e18;

  while (r - l > 1) {
    ll m = (r - l) / 2 + l;
    ll cnt = count_greater(m);

    if (cnt > k) {
      l = m;
    } else {
      r = m;
    }
  }

  ll A = l;
  ll B = 1ll * a.back() * b.back();
  cout << A << ' ' << B;
}
