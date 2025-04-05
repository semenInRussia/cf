// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  int m;
  cin >> m;

  int cur = 0;
  vector<int> b = {0};

  auto add = [&](int v) {
    v = v >= x;
    b.push_back(v + b.back());
    cur++;
  };

  int fr = 0; // front index
  auto rem = [&]() { fr++; };

  auto answ = [&](int k) { return b[fr + k] - b[fr]; };

  for (int x : a) {
    add(x);
  }

  for (int i = 0; i < m; i++) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int a;
      cin >> a;
      add(a);
    }
    if (typ == 2) {
      rem();
    }

    if (typ == 3) {
      int k;
      cin >> k;
      cout << answ(k) << "\n";
    }
  }
}
