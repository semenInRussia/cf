// semenInRussia 2025
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int tt, v;
  cin >> tt >> v;

  assert(v == 1);

  while (tt--) {
    int n;
    cin >> n;

    // get s - side of square
    int s = int(sqrt(n));
    if (1ll * s * s < n) {
      s++;
    }
    vector<string> t(s, string(s, '#'));

    int k = s * s - n;

    while (k >= s) {
      k -= s;
      t.pop_back();
    }

    for (int j = 0; j < k; j++) {
      t[0][j] = '.';
    }

    cout << t.size() << " " << s << "\n";

    for (auto row : t) {
      cout << row << "\n";
    }
  }
}
