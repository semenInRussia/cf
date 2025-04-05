// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

int ask(int m) {
  cout << m << endl;
  int t;
  cin >> t;
  if (t == 0) {
    exit(0);
  }
  return t;
}

int main() {
  int n;
  cin >> n;
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

  assert(false && "unreach!");
}
