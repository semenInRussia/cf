// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>
using namespace std;

const int INF = int(1e9);

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;
  int ans_l = -INF, ans_r = +INF;
  for (int i = 1; i < n; i++) {
    int a = arr[i - 1], b = arr[i];
    int p1 = (a + b) / 2;
    int p2 = (a + b + 1) / 2;

    int l = 0, r = +INF;
    if (a < b)
      l = 0, r = p1;
    else if (a > b)
      l = p2, r = +INF;
    ans_l = max(ans_l, l), ans_r = min(ans_r, r);
  }

  cout << ((ans_l <= ans_r) ? ans_l : -1) << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
