// semenInRussia 2024
// https://codeforces.com/contest/1994/problem/E
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e6 + 100;
int sum[N];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int n;
      cin >> n;
      sum[i] = n;
      int _x;
      for (int i = 1; i < n; i++)
        cin >> _x;
    }
    sort(sum, sum + k);

    int ans = 0;
    for (int i = k - 1; i >= 0; i--) {
      int l = __lg(ans & sum[i]);
      if (l != -1)
        ans |= (1 << l) - 1;
      ans |= sum[i];
    }
    cout << ans << '\n';
  }
}
