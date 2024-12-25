// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

const int N = 2e5;

int ans[N];

map<pair<int, int>, bool> memo;

bool qry(int a, int b) {
  if (memo.count({a, b})) {
    return memo[{a, b}];
  }
  if (a == b) {
    return 0;
  }
  cout << "? " << a << " " << b << endl;
  int r;
  cin >> r;
  return memo[{a, b}] = r;
}

void solve() {
  int n;
  cin >> n;

  memo.clear();

  int i = 2;

  for (; i < n; i++) {
    ans[i] = 0;
    if (!qry(i, 1)) {
      ans[i] = 1;
      break;
    }
  }

  for (int j = 1; j < n; j++) {
    int cur = j;
    while (i < n && !qry(i, j)) {
      ans[i] = cur;
      cur = i;
      i++;
    }
  }

  cout << "! ";
  for (int i = 1; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
