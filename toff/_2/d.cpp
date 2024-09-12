// semenInRussia 2024
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

const int N = 33;

void solve() {
  ll x;
  cin >> x;
  ll t = x;
  vector<int> num;
  while (t) {
    num.push_back(t % 3);
    t /= 3;
  }

  int c = 0;
  int sz = int(num.size());
  for (int i = 0; i < sz || c; i++) {
    if (i < sz) {
      num.push_back(0);
    }
    num[i] += 1 + c;
    c = 0;
    if (num[i] >= 2) {
      c = num[i] - 2;
    }
  }
  for (int &x : num) {
    x--;
  }
  cout << '\n' << x << '\n';
  for (int x : num) {
    cout << x << ' ';
  }
  cout << '\n';
  for (int i = 0; i < sz; i++) {
    cout << (1 << i) << ' ';
  }
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
