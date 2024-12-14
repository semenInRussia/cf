// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> fact[N];

const int mod = 998244353;

struct mi {
  int v;
  mi(int64_t x = 0) : v(x % mod) { v += mod * (x < 0); }
  explicit operator int() { return v; }
};

ostream &operator<<(ostream &out, mi v) { return out << v.v; }

mi operator*(mi a, mi b) { return mi(1ll * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }

mi operator+(mi a, mi b) { return mi(1ll * a.v + b.v); }
mi &operator+=(mi &a, mi b) { return a = a + b; }

mi operator-(mi a, mi b) { return mi(a.v - b.v); }
mi &operator-=(mi &a, mi b) { return a = a - b; }

mi pow(mi x, int k) {
  mi ans = 1;
  while (k) {
    if (k & 1) {
      ans *= x;
    }
    x *= x;
    k >>= 1;
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;

  mi ans = pow(m, n);

  for (int j = 2; j <= m; j++) {
    mi op = pow(m / j, n);

    int sz = (int)fact[j].size();

    if (sz == 0) {
      continue;
    }

    if (sz & 1) {
      ans -= op;
    } else {
      ans += op;
    }
  }

  cout << ans << "\n";
}

vector<int> facts(int n) {
  vector<int> ans;

  while (n % 2 == 0) {
    ans.push_back(2);
    n /= 2;
  }

  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      ans.push_back(i);
      n /= i;
    }
  }

  if (n > 2) {
    ans.push_back(n);
  }

  return ans;
}

int main() {
  for (int i = 2; i < N; i++) {
    fact[i] = facts(i);
    for (int j = 1; j < fact[i].size(); j++) {
      if (fact[i][j] == fact[i][j - 1]) {
        fact[i].clear();
      }
    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
