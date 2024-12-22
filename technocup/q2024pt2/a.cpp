// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 1e6;
int a[N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx += a[i];
  }

  int mn = *min_element(a, a + n);

  cout << mx << " " << mn << "\n";
}
