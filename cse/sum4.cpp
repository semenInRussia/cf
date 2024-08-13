// semenInRussia 2024
// https://cses.fi/problemset/task/1631
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int N = 2e5;
int a[N];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  using sum2 = pair<int, pii>; // sum of 2 elements and their indexes
  set<sum2> r;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      r.insert({a[i] + a[j], {i, j}});
    }
  }

  bool ok = false;
  pair<pii, pii> ans;
  for (int i = 0; i < n && !ok; i++) {
    // if one of l, with one of r, that it's ans,
    // but check only added, this amount is n

    // on every iteration, remove all pair {j, i} from r, and add them to l,
    // check them
    vector<sum2> tokill, tocheck;

    for (int j = 0; j < i; j++) {
      tocheck.push_back({a[i] + a[j], {j, i}});
    }
    tokill = tocheck;
    for (int j = i + 1; j < n; j++) {
      tokill.push_back({a[j] + a[i], {i, j}});
    }
    for (auto s : tokill) {
      r.erase(s);
    }
    for (auto s : tocheck) {
      int sm1 = s.first;
      int sm2 = x - sm1;
      auto it = r.lower_bound({sm2, {-1, -1}});
      if (it != r.end() && it->first == sm2) {
        ok = 1;
        ans = {s.second, it->second};
        break;
      }
    }
  }

  if (ok)
    for (pii p : {ans.first, ans.second})
      cout << (p.first + 1) << ' ' << (p.second + 1) << ' ';
  else
    cout << "IMPOSSIBLE";
}
