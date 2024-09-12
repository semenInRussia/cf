// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int M = 1e5;
int w[M];
ll wish[M];

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c;
      cin >> c;
      wish[i] += 1ll * w[j] * c;
    }
  }
  sort(wish, wish + n);
  int r = d;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (r >= wish[i]) {
      r -= wish[i];
      ans++;
    }
  }
  cout << ans;
}
