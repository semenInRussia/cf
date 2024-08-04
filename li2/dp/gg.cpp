// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 2100, M = 110;
string dict[N];
bool f[M], space[M];
int p[M];
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> dict[i];
  f[0] = 1;
  p[0] = -1;
  int m = (int)s.size();
  for (int i = 1; i <= m; i++) {
    for (auto w : dict) {
      int sz = int(w.size());
      if (i < sz)
        continue;
      if (f[i - sz]) {
        f[i] = s.substr(i - sz, sz) == w;
        p[i] = i - sz;
      }
      if (f[i])
        break;
    }
  }
  int j = p[m];
  while (j != 0) {
    space[j] = 1;
    j = p[j];
  }
  for (int i = 0; i < m; i++) {
    if (space[i])
      cout << ' ';
    cout << s[i];
  }
}
