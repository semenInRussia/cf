// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  int n, q;
  cin >> n >> q;

  vector<ull> prv(n + 1), a(n + 1, 0);
  unordered_set<int> s;
  ull cur = 0;
  for (int t = 0; t < q; t++) {
    int x;
    cin >> x;
    if (s.count(x))
      s.erase(x), a[x] += cur - prv[x];
    else
      s.insert(x), prv[x] = cur;
    cur += s.size();
  }

  for (int j : s)
    a[j] += cur - prv[j];

  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
}
