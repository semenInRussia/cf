// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int closed = 0;
  for (int i = 0; i < n; i++) {
    int cur;
    cin >> cur;
    closed += cur;
  }

  bool ok;

  if (n == 1) {
    ok = closed == 1;
  } else {
    ok = closed == n - 1;
  }

  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
