// semenInRussia 2024
// https://codeforces.com/contest/2050/problem/C
#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int N = 1e6;
bool can[N];

void solve() {
  string s;
  cin >> s;

  int64_t x = 0;
  int a = 0;
  int b = 0;
  for (char d : s) {
    d -= '0';
    x += d;
    a += d == 2;
    b += d == 3;
  }

  // a=>2
  // b=>6

  int o = x % 9;

  vector<bool> can(10);

  can[o] = 1;

  for (int i = 0; i < a; i++) {
    vector<int> p;
    for (int j = 0; j < 10; j++) {
      if (can[j]) {
        p.push_back((j + 2) % 9);
      }
    }
    for (int x : p) {
      can[x] = 1;
    }
  }

  for (int i = 0; i < b; i++) {
    vector<int> p;
    for (int j = 0; j < 10; j++) {
      if (can[j]) {
        p.push_back((j + 6) % 9);
      }
    }
    for (int x : p) {
      can[x] = 1;
    }
  }

  int d = 9 - o;
  bool ok = can[0] || can[9];

  cout << (ok ? "YES\n" : "NO\n");
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
