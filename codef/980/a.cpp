// semenInRussia 2024
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int x = max(0, b - a);
    cout << max(0, a - x) << '\n';
  }
}
