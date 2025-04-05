// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int ask(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  int p;
  cin >> p;
  if (p == -1) {
    exit(0);
  }
  return p;
}

void solve() {
  int n;
  cin >> n;

  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    r[i] = i + 1;
  }

  mt19937 mt(231);
  shuffle(r.begin(), r.end(), mt);

  int a = r.back();
  r.pop_back();
  int b = r.back();
  r.pop_back();
  int c = r.back();
  r.pop_back();

  while (true) {
    int p = ask(a, b, c);
    if (p == 0) {
      cout << "! " << a << " " << b << " " << c << endl;
      return;
    }
    if (rand() % 2) {
      c = p;
    } else {
      b = p;
    }
  }
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
