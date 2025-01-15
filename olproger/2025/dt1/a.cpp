// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 2e5;
int a[N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    a[i] = min(w, h);
  }

  sort(a, a + n);

  int ans = 0;

  int j = 0;

  for (int v = 1; true; v += 2) {
    while (j < n && a[j] < v) {
      j++;
    }
    if (j == n) {
      break;
    }
    ans++;
    j++;
  }

  cout << ans;
}
