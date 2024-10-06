// semenInRussia 2024
// https://codeforces.com/contest/2021/problem/B
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 2e5 + 100;
int a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    map<int, vector<int>> b;
    for (int i = 0; i < n; i++) {
      b[a[i] % x].push_back(a[i]);
    }

    multiset<int> s;

    for (auto [mod, vals] : b) {
      int cur = -1;
      sort(vals.begin(), vals.end());
      for (int v : vals) {
        if (v > cur) {
          cur = v;
        } else {
          cur += x;
        }
        s.insert(cur);
      }
    }

    // compute mex
    int mex = 0;
    for (int el : s) {
      if (mex == el) {
        mex++;
      }
    }
    cout << mex << '\n';
  }
}
