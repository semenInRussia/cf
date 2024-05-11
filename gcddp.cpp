// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1955/G
// #dp *1900

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int maxn = 105;
ll a[maxn][maxn];
unordered_set<ll> d[maxn][maxn];
int n, m;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j], d[i][j].clear();

    a[0][0] = gcd(a[0][0], a[n - 1][m - 1]);
    d[0][0].insert(a[0][0]);
    for (int i = 1; i < n; i++) {
      ll prv = *d[i - 1][0].begin();
      d[i][0].insert(gcd(prv, a[i][0]));
    }
    for (int j = 1; j < m; j++) {
      ll prv = *d[0][j - 1].begin();
      d[0][j].insert(gcd(prv, a[0][j]));
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        ll cur = a[i][j];
        for (ll a : d[i][j - 1])
          d[i][j].insert(gcd(cur, a));
        for (ll b : d[i - 1][j])
          d[i][j].insert(gcd(cur, b));

        vector<ll> tokill;
        for (ll x : d[i][j])
          for (ll y : d[i][j])
            if (x != y && x % y == 0)
              tokill.push_back(y);
        for (ll x : tokill)
          d[i][j].erase(x);
      }
    }

    cout << *max_element(all(d[n - 1][m - 1])) << endl;
  }
}
