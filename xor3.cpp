// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
