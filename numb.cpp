// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 5e4, inf = 1e9;
string dict[N];
const string keyb[10] = {
    "oqz", // 0
    "ij",  // 1,
    "abc", // 2,
    "def", // 3,
    "gh",  // 4,
    "kl",  // 5,
    "mn",  // 6,
    "prs", // 7,
    "tuv", // 8,
    "wxy", // 9,
};

int f[200], nxt[200];

bool solve() {
  string numb;
  cin >> numb;
  if (numb == "-1")
    return false;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> dict[i];

  int m = int(numb.size());
  fill(f, f + m, +inf);

  for (int i = m - 1; i >= 0; i--) {
    // f[i] - we can do [i; n)
    for (int j = 0; j < n; j++) {
      int len = int(dict[j].size());
      int r = i + len;
      if (r > m || f[r] == -1 || f[i] <= f[r] + 1)
        continue;

      // check: [i; i + dict[j].size()) = dict[j]
      bool ok = 1;
      for (int k = 0; k < len; k++) {
        if (keyb[numb[i + k] - '0'].find(dict[j][k]) == string::npos) {
          ok = false;
          break;
        }
      }

      if (ok) {
        nxt[i] = j;
        f[i] = f[r] + 1;
      }
    }
  }

  if (f[0] == inf)
    cout << "No solution.";
  else {
    int i = 0;
    cout << dict[nxt[0]];
    i += (int)dict[nxt[0]].size();
    while (i < m) {
      cout << ' ' << dict[nxt[i]];
      i += int(dict[nxt[i]].size());
    }
  }
  cout << '\n';

  return true;
}

int main() {
  while (1)
    if (!solve())
      break;
}
