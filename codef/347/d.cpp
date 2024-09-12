// Copyright 2024 semenInRussia

#include <bitset>
#include <iostream>
using namespace std;

using ull = unsigned long long;

int main() {
  int a, b;
  ull _c;
  cin >> a >> b >> _c;

  bitset<60> c = _c, x, y;
  int o = c.count();

  int ok = 0, oa = 0, ob, z;
  // z=2, oa=1, ob=2
  for (; oa <= o; oa++) {
    ob = o - oa;
    z = a - oa;
    if (oa > a || ob > b || z > (60 - o))
      continue;
    if (oa + z == a && ob + z == b) {
      ok = 1;
      break;
    }
  }

  if (!ok) {
    cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < 60; i++) {
    if (c[i] == 1) {
      if (oa) {
        oa--, x[i] = 1;
      } else if (ob) {
        ob--, y[i] = 1;
      }
    }

    if (c[i] == 0 && z) {
      z--;
      x[i] = 1, y[i] = 1;
    }
  }

  cout << x.to_ullong() << ' ' << y.to_ullong() << endl;
}
