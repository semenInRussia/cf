// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int n = 8;
int a[] = {1, 6, 11, 12, 6, 12, 3, 6};

int main() {
  for (int j = 0; j < n; j++) {
    vector<int> _a;
    for (int i = 0; i < n; i++)
      if (i != j)
        _a.push_back(a[i]);
    vector<int> b(n - 2);
    for (int i = 0; i < n - 2; i++)
      b[i] = gcd(_a[i], _a[i + 1]);
    if (is_sorted(b.begin(), b.end()))
      cout << "OK!" << j << " " << '\n';
  }
}
