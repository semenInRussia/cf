// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 1e5;
const int mod = 1e9 + 7;
int n[N], k[N];

int solve(int a, int b) {
  // return 2^b
  int p = 2;
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (1ll * ans * p) % mod;
    }
    p = (1ll * p * p) % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> n[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < m; i++) {
    cout << solve(n[i], k[i]) << '\n';
  }
}
