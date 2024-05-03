// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

void solve_first() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  cout << s << endl;
}

void solve_second() {
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  for (int k = 0; k < n; k++) {
    // s is a+b,
    // check b+a == t
    string a = s.substr(0, k);
    string b = s.substr(k, n - k);
    if (b + a == t) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
  return;
}

int main() {
  string typ;
  cin >> typ;

  if (typ == "first") {
    solve_first();
  } else {
    solve_second();
  }
}
