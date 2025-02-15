// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int a = min(n, 2);
  int b = n <= 4 ? n : n - 1;

  cout << n - 1 << "\n";

  for (int i = a; i <= b; i++) {
    cout << i << " " << n << "\n";
  }
}
