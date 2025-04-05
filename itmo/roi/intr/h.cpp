// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <random>

using namespace std;

int main() {
  string h = "DDDDRRRUL";

  mt19937 mt(128);
  uniform_int_distribution<> u(0, h.size());

  auto prv = 'p';

  while (1) {
    int j = u(mt) % h.size();
    while (h[j] == prv) {
      j = u(mt) % h.size();
    }
    prv = h[j];
    cout << h[j] << endl;
    char c;
    cin >> c;
    assert(c != 'E');
    if (c == 'Y') {
      break;
    }
  }
}
