// semenInRussia 2024
// https://codeforces.com/gym/105572/problem/A
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int c = b - a + 1;
  int ans = c * (c - (a == 0));

  cout << ans;
}
