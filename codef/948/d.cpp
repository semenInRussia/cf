// semenInRussia 2024
#include <bitset>
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 3e5;
string t[maxn];
bitset<maxn> cols[maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> t[i];

  // fill row
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cols[j][i] = t[i][j] == '1';
  }

  // col 1 and 2
  // - <=2 different places

  bitset<maxn> a, b;
  int k = (a ^ b).count();

  // (a ^ b) = 0
  // b ^ c = 2
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
