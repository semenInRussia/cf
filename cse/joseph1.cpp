// semenInRussia 2024
// https://cses.fi/problemset/task/1084
#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(i + 1);
  }
  int k = 0;
  for (int z = 0; z < n; z++) {
    for (int _ : {1, 2}) {
      auto it = s.upper_bound(k);
      k = it == s.end() ? *s.begin() : *it;
    }
    s.erase(k);
    cout << k << ' ';
  }
}
