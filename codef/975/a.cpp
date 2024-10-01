// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2000;
int a[N];
ll f[N], g[N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      g[i] = f[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(a[i] + (n + (~i & 1)) / 2, ans);
    }
    cout << ans << '\n';
  }
}
