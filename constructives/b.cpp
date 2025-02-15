// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 500;
int a[N][N];

int main() {
  int n;
  cin >> n;

  // build the NxN good matrix

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int d = (x - i * i) % n;
    if (d < 0) {
      d += n;
    }
    for (int j = 0; j < n; j++) {
      a[i][j] = (d + i * j) % n;
      if (a[i][j] < 0) {
        a[i][j] += n;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}
