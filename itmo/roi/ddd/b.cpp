// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1e5 + 100;
int p[N];
bool used[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }

  int m;
  cin >> m;
  for (int j = 0; j < m; j++) {
    int x, y;
    cin >> x >> y;
  }
  cout << "-1";
}
