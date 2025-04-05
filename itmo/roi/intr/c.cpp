// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

int typ;

int ask(int m) {
  if (typ == 1) {
    cout << m << endl;
  }
  int t;
  cin >> t;
  if (t == 0) {
    if (typ == 2) {
      cout << m << endl;
    }
    exit(0);
  }
  return t;
}

int main() {
  cin >> typ;
  int n;
  cin >> n;

  if (typ == 2) {
    int q;
    cin >> q;
  }

  int l = 0;
  int r = n + 1;

  while (r - l > 1) {
    int m = (l + r) / 2;
    if (ask(m) == -1) {
      r = m;
    } else {
      l = m;
    }
  }
}
