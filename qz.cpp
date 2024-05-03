#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

const ll inf = 1e17;
const ll MAXM = 1e5;
vector<ll> factors[MAXM + 5];

long long num;
void init() {
  for (ll i = 1; i <= MAXM; i++) {
    for (ll j = i; j <= MAXM; j += i) {
      factors[j].pb(i);
    }
  }
}

void add(long long x, vector<ll> &f, long long m) {
  for (auto y : factors[x]) {
    if (y > m) {
      break;
    } else {
      f[y]++;
      if (f[y] == 1) {
        num++;
      }
    }
  }
}

void remove(long long x, vector<ll> &f, long long m) {
  for (auto y : factors[x]) {
    if (y > m) {
      break;
    } else {
      f[y]--;
      if (f[y] == 0) {
        num--;
      }
    }
  }
}

bool good(long long m) { return num == m; }

void solve() {
  num = 0;
  ll n, m;
  cin >> n >> m;
  vector<ll> vec;
  for (ll i = 0; i < n; i++) {
    ll value;
    cin >> value;
    vec.pb(value);
  }
  sort(all(vec));
  vector<ll> f(m + 5, 0);
  ll l = 0;
  ll res = inf;
  for (ll r = 0; r < n; r++) {
    add(vec[r], f, m);
    while (good(m)) {
      remove(vec[l], f, m);
      l++;
    }
    if (l > 0) {
      res = min(res, (vec[r] - vec[l - 1]));
    }
  }
  if (res == inf) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}

int main() {
  init();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
