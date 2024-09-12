// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

int sum_digs(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main() {
  int t = 0;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i <= n; i++) {
      ans += sum_digs(i);
    }
    cout << ans << endl;
  }
}
