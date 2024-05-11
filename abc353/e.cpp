// Copyright 2024 semenInRussia
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll k, sx, sy, tx, ty;
  cin >> k >> sx >> sy >> tx >> ty;
  ll x = abs(tx - sx), y = abs(ty - sy);
  cout << (x / k + y / k) << '\n';
}
