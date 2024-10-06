// semenInRussia 2024
// https://codeforces.com/contest/2021/problem/A
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int a[100];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    multiset<int> s(a, a + n);
    while (s.size() > 1ull) {
      auto a = s.begin();
      auto b = next(a);
      int c = (*a + *b) / 2;
      s.insert(c);
      s.erase(a);
      s.erase(b);
    }
    cout << *s.begin() << '\n';
  }
}
