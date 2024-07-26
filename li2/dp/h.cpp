// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 1e3;
int a[N], f[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[j] < a[i])
        f[i] = max(f[i], f[j] + 1);
    ans = max(ans, f[i]);
  }
  cout << ans;
}
