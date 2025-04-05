// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 100;
string t[N], t2[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int c, q;
  cin >> c >> q;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  string h = "RGBRGB";

  for (int l : {0, 1}) {
    for (char c : h) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        t2[i] = t[i];
        for (int j = 0; j < m; j++) {
          int o = (i + j + l) % 2;
          if (o) {
            t2[i][j] = c;
          } else if (t2[i][j] == c) {
            t2[i][j] = c == 'B' ? 'R' : ('R' + 'G') - c;
          }
          cnt += t2[i][j] != t[i][j];
        }
      }

      if (cnt <= q) {
        for (int i = 0; i < n; i++) {
          cout << t2[i] << "\n";
        }
        return 0;
      }
    }
  }

  assert(0 && "unreach!");
}
