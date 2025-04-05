// semenInRussia 2025
#include <iostream>
using namespace std;
#define int long long

int c00, c01, c10, c11;

bool check(string &s) {
  int b00 = 0, b01 = 0, b10 = 0, b11 = 0;
  int c0 = 0;
  int c1 = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '1') {
      b01 += c0;
      b11 += c1;
    } else {
      b00 += c0;
      b10 += c1;
    }
    c0 += s[i] == '0';
    c1 += s[i] == '1';
  }

  return c00 == b00 && b01 == c01 && b10 == c10 && b11 == c11;
}

int bin(int x) {
  int l = 1;
  int r = 1e9 + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (m * (m - 1) / 2 <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  if (l * (l - 1) / 2 != x) {
    cout << "Impossible\n";
    exit(0);
  }
  return l;
}

signed main() {
  int a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;

  c00 = a00;
  c01 = a01;
  c10 = a10;
  c11 = a11;

  int z = bin(a00);
  int o = bin(a11);

  if (a00 + a11 + a01 + a10 == 0) {
    cout << "0\n";
    return 0;
  }

  if (min(a00, a11) == 0 && a01 + a10 == 0) {
    if (z == 1) {
      z = 0;
    }
    if (o == 1) {
      o = 0;
    }
    cout << string(z, '0') << string(o, '1') << "\n";
    return 0;
  }

  string s(o + z, '0');

  if (o * z != a01 + a10) {
    cout << "Impossible\n";
    return 0;
  }

  for (int i = 0; i < (int)s.size(); i++) {
    if (z == 0 || a01 < o) {
      s[i] = '1';
      a10 -= z;
      o--;
    } else {
      a01 -= o;
      z--;
    }
  }

  cout << s << "\n";
}
