// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>

using namespace std;

bool ask(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int t;
  cin >> t;
  if (t == -1) {
    exit(0);
  }
  return t;
}

int main() {
  int n;
  cin >> n;

  mt19937 mt(228);

  vector<int> r(n);

  for (int i = 0; i < n; i++) {
    r[i] = 1 + i;
    // cerr << r[i] << " ";
  }
  // cerr << "\n";
  shuffle(r.begin(), r.end(), mt);

  auto pick = [&]() {
    int l = r.back();
    r.pop_back();
    return l;
  };

  int i = pick();
  int j = pick();
  int k = pick();

  int l[3] = {i, j, k};

  while (1) {
    shuffle(l, l + 3, mt);
    if (ask(l[0], l[1], l[2])) {
      i = l[0];
      j = l[1];
      k = l[2];
      break;
    }
  }

  for (int l = 0; l < n && !r.empty(); l++) {
    k = pick();
    bool v = ask(i, j, k);
    if (v == 1) {
      continue;
    }
    if (ask(i, k, j)) {
      j = k;
    } else {
      i = k;
    }
  }

  cout << "! " << i << " " << j << endl;
}
