// semenInRussia 2024
// https://codeforces.com/gym/104949/problem/3
// or
// https://acmp.ru/asp/do/index.asp?main=course&id_course=3
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

#define isz(x) int(x.size())
#define popc(x) __builtin_popcount(x)

const int N = 16;
int a[N][N];
vector<int64_t> col[1 << N];

int64_t sum(vector<int64_t> &s, int b) {
  int64_t ans = 0;
  for (int j = 0; j < int(s.size()); j++) {
    if ((b >> j) & 1) {
      continue;
    }
    ans += s[j];
  }
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  // --

  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  // 1. for every row config, compute columns values
  // O(2^15 * 15 * 15)
  for (int b = 0; b < (1 << h); b++) {
    auto &s = col[b];
    s.resize(w, 0);
    for (int i = 0; i < h; i++) {
      if ((b >> i) & 1) { // we must erase this row
        continue;
      }
      for (int j = 0; j < w; j++) {
        s[j] += a[i][j];
      }
    }
  }

  // 2. iterate over row config, divide columns values on 2 parts, find at them
  // sums, check all possible sums of 1part, check all possible 2part, for every
  // sum of 2part check did it before, if did, then answer is columns configs +
  // concat row configs

  int64_t x;
  cin >> x;

  unordered_map<int64_t, int> p1;

  for (int b = 0; b < (1 << h); b++) {
    auto &s = col[b];
    vector<int64_t> t = {};
    while (s.size() > t.size()) {
      t.push_back(s.back());
      s.pop_back();
    }
    reverse(t.begin(), t.end());

    p1.clear();
    for (int f = 0; f < (1 << isz(s)); f++) {
      auto v = sum(s, f);
      // p1.push_back({sum(s, f), f});
      p1[v] = f;
    }

    for (int f = 0; f < (1 << isz(t)); f++) {
      auto v = sum(t, f);
      if (p1.count(x - v)) {
        cout << "YES\n";
        int b1 = p1[x - v];
        int u = (f << isz(s)) | b1;

        int k = popc(b) + popc(u);
        cout << k << "\n";

        // check rows
        for (int j = 0; j < h; j++) {
          if ((b >> j) & 1) {
            cout << "1 " << (j + 1) << "\n";
          }
        }

        // check columns
        for (int j = 0; j < w; j++) {
          if ((u >> j) & 1) {
            cout << "2 " << (j + 1) << "\n";
          }
        }

        return 0;
      }
    }
  }

  cout << "NO";
}
