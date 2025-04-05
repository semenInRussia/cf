// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> ans;

int row = 0;
int col = 0;

int offs = 0;

void f(int k) {
  if (k == 0) {
    return;
  }
  if (k == 1) {
    if (ans.empty()) {
      ans.push_back({0, 0});
      ans.push_back({0, 2});
    } else {
      auto [x, y] = ans[offs++];
      ans.push_back({x + 1, y});
    }
    return;
  }
  // if (k == 2) {
  //   if (ans.empty()) {
  //     ans.push_back({0, 0});
  //   }
  // }
  int len = 0;
  while ((len + 1) * len / 2 <= k) {
    len++;
  }
  // cerr << "k=" << k << ", len=" << len << "\n";
  for (int i = 0; i < len; i++) {
    ans.push_back({row, col});
    col++;
  }
  k -= (len - 1) * len / 2;
  row += 2;
  f(k);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    // cerr << "k=" << k << "\n";
    row = -1e9;
    col = -1e9;
    offs = 0;
    ans.clear();
    f(k);
    cout << ans.size() << "\n";
    assert(ans.size() <= 500);
    for (auto [x, y] : ans) {
      cout << x << " " << y << "\n";
    }
  }
}
