// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int na = 0;
    int nb = 0;
    for (auto ch : s) {
      na += ch == 'A';
      nb += ch == 'B';
    }
    if (na > nb)
      cout << 'A' << endl;
    else
      cout << 'B' << endl;
  }
}
