// semenInRussia 2024
// https://codeforces.com/contest/1475/problem/A
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    while (n % 2 == 0)
      n /= 2;
    cout << (n > 1 ? "YES\n" : "NO\n");
  }
}
