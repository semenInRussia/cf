// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i] > a[0]) {
      cout << (i + 1) << '\n';
      return 0;
    }
  }

  cout << "-1\n";
}
