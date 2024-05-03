// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  {
    int n;
    cin >> n;

    vector<string> f(n);
    for (auto &row : f)
      cin >> row;

    vector<int> cnt1(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt1[i] += f[i][j] == '1';
      }
    }

    int side = 0;

    for (auto c : cnt1) {
      if (c == 0)
        continue;
      if (side == 0) {
        side = c;
      } else {
        if (side == c)
          cout << "SQUARE" << endl;
        else
          cout << "TRIANGLE" << endl;
        break;
      }
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
