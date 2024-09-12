// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  cout << (n / 4 + (n - (n / 4) * 4) / 2) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
