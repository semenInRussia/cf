// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 1e5;
int p[maxn], q[maxn];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    set<int> nums;
    for (int i = 0; i < n; i++)
      cin >> p[i], nums.insert(i + 1);
    for (int i = 0; i < n; i++)
      q[i] = -1;
    int imx = max_element(p, p + n) - p;
    for (int i = imx & 1; i < n; i += 2)
      q[i] = *nums.begin(), nums.erase(q[i]);
    for (int i = ~imx & 1; i < n; i += 2)
      q[i] = *nums.rbegin(), nums.erase(q[i]);
    for (int i = 0; i < n; i++)
      cout << q[i] << " \n"[i == n - 1];
  }
}
