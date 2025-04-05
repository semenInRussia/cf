// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <unordered_map>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  unordered_map<string, int> h;

  string s;
  int v;

  while (cin >> s >> v) {
    h[s] += v;
    cout << h[s] << "\n";
  }
}
