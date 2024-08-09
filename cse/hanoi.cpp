// semenInRussia 2024
// https://cses.fi/problemset/task/2165
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<pii> ans;
void op(int a, int b) { ans.push_back({a, b}); }

//
//       i
// iii  ii
void f(int n, int a, int b, int c) {
  if (n == 1) {
    op(a, c);
    return;
  }
  f(n - 1, a, c, b);
  op(a, c);
  f(n - 1, b, a, c);
}

int main() {
  int n;
  cin >> n;
  f(n, 1, 2, 3);
  cout << ans.size() << '\n';
  for (auto [a, b] : ans)
    cout << a << ' ' << b << '\n';
}
