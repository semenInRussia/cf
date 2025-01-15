// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1005;

string t[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  bool ok = true;

  for (int i = 0; i < n && ok; i++) {
    for (int j = 0; j < m && ok; j++) {
      if (t[i][j] == '+') {
        continue;
      }
      if (i + 1 == n || j + 1 == m) {
        ok = false;
      }
      for (int ip : {i, i + 1}) {
        for (int jp : {j, j + 1}) {
          t[ip][jp] = ('+' + '-') - t[ip][jp];
        }
      }
    }
  }

  cout << (ok ? "Yes" : "No");
}
