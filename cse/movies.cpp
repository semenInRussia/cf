// semenInRussia 2024
// https://cses.fi/problemset/task/1629
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
pair<int, int> p[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p[i] = {a, b};
  }
  sort(p, p + n, [](auto a, auto b) { return a.second < b.second; });

  int ans = 0;
  int prv = -1;
  for (int i = 0; i < n; i++) {
    auto [a, b] = p[i];
    if (a >= prv)
      ans++, prv = b;
  }

  cout << ans;
}
