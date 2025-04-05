// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1005;
int a[N][N];

int main() {
  int n;
  cin >> n;

  for (int j = 0; j < n; j++) {
    a[j][j] = 0;
    for (int i = 1; i < n; i++) {
      a[(i + j) % n][j] = i;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}
