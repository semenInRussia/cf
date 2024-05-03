// Copyright 2024 semenInRussia
#include <iostream>
#include <set>
using namespace std;

int main() {
  int n, x;
  cin >> x >> n;

  multiset<int> p = {0, x}, ans = {x};
  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;

    auto it = p.insert(pos);
    int nxt = *next(it), prv = *prev(it);

    ans.erase(ans.find(nxt - prv));
    ans.insert(pos - prv);
    ans.insert(nxt - pos);

    cout << *ans.rbegin() << ' ';
  }
}
