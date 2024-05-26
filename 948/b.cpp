// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
  int x;
  cin >> x;
  vector<int> ans(32);
  for (int i = 0; (1 << i) <= x; i++)
    ans[i] = (x >> i) & 1;

  int n = (int)ans.size();
  for (int i = 0; i + 1 < 32; i++) {
    if (ans[i] == 2 || (ans[i] != 0 && ans[i + 1] != 0)) {
      ans[i] -= 2;
      ans[i + 1]++;
    }
  }

  cout << (int)ans.size() << '\n';
  for (auto d : ans)
    cout << d << ' ';
  cout << "\n\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
