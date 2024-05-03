// Copyright 2024 semenInRussia

#include <numeric>
using namespace std;

#include <iostream>

int main() {
  int n, p, q;
  cin >> n >> p >> q;

  string s;
  cin >> s;

  bool found = false;
  int l, k;

  // l is q-strings amount
  // k is p-strings amount

  for (l = 0; l <= (n / q); l++) {
    // ql + pk = n
    k = (n - q * l) / p;
    if (k * p + q * l == n) {
      found = true;
      break;
    }
  }

  // cout << "k = " << k << endl;
  // cout << "l = " << l << endl;

  if (!found) {
    cout << "-1" << endl;
    return 0;
  }

  cout << k + l << endl;

  // q strings
  for (int i = 0; i < l; i++) {
    cout << s.substr(i * q, q) << endl;
  }

  // p strings
  for (int i = 0; i < k; i++) {
    cout << s.substr(l * q + i * p, p) << endl;
  }

  return 0;
}
