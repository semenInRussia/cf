#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  for (auto &di : d)
    cin >> di;

  vector<int> r(n, INT32_MAX);
  int zero = -1;
  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      r[i] = 0;
      zero = i;
      continue;
    }

    if (zero != -1) {
      r[i] = i - zero;
    }
  }

  zero = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (d[i] == 0) {
      r[i] = 0;
      zero = i;
      continue;
    }

    if (zero != -1) {
      r[i] = min(r[i], zero - i);
    }
  }

  for (auto &ri : r)
    cout << ri << ' ';
  cout << endl;

  return 0;
}
