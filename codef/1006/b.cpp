// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;

    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
      a += s[i] == '-';
      b += s[i] == '_';
    }

    long long ans = 1ll * b * (a / 2) * (a - a / 2);
    cout << ans << "\n";
  }
}
