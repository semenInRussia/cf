#include <bits/stdc++.h>
using namespace std;

const int ADD = 0, SUB = 1, MULT = 2, DIV = 3;

multiset<int> nums;

int x;

using var = pair<pair<vector<int>, vector<int>>, int>;
var cur, bst;

void f() {
  if (abs(cur.second - x) < abs(bst.second - x)) {
    bst = cur;
  }

  for (int op : {ADD, SUB, MULT, DIV}) {
    int g = cur.second;
    for (int v : nums) {
      int old = g;

      if (op == ADD) {
        g += v;
      }
      if (op == SUB) {
        if (g - v <= 0) {
          continue;
        }
        g -= v;
      }
      if (op == MULT) {
        g *= v;
      }
      if (op == DIV) {
        if (g % v) {
          continue;
        }
        g /= v;
      }

      cur.first.first.push_back(v);
      cur.first.second.push_back(op);
      nums.erase(v);
      f();
      nums.insert(v);
      cur.first.first.pop_back();
      cur.first.second.pop_back();

      g = old;
    }
  }
}

void solve() {
  int a[6];
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
    nums.insert(a[i]);
  }
  cin >> x;
  bst = {{{a[0]}, {}}, a[0]};

  for (int i = 0; i < 6; i++) {
    int v = a[i];
    nums.erase(nums.find(v));
    cur.first.first.push_back(v);
    f();
    cur.first.first.pop_back();
    nums.insert(v);
  }

  cout << "Target: " << x << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
