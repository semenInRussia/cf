// semenInRussia 2024
// https://cses.fi/problemset/task/1073
#include <iostream>
#include <set>
using namespace std;
const int inf = 1e9 + 100;

int main() {
  multiset<int> t = {-inf, +inf}; // towers
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    // find the >
    auto it = t.upper_bound(x);
    if (*it == +inf)
      t.insert(x); // new tower
    else
      t.erase(it), t.insert(x);
  }

  cout << t.size() - 2; // ignore +-inf
}
