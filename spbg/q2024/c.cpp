// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> a, b;
  a = {0, 0};
  b = {n - 1, m - 1};
  while (1) {
    char c;
    cin >> c;

    if (c == 'R') {
      a.second++;
    } else {
      a.first++;
    }

    int w = b.first - a.first;
    int h = b.second - a.second;

    assert(w >= 0 && h >= 0);

    if (w > h) {
      cout << 'D' << endl;
      b.first--;
    } else {
      cout << 'L' << endl;
      b.second--;
    }
    if (a == b) {
      break;
    }
  }
}
