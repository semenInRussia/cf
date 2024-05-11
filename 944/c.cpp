// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  unordered_set<int> h1;
  if (a > b)
    swap(a, b);
  for (int i = a; i <= b; i++)
    h1.insert(i);

  if (h1.count(c) ^ !h1.count(d))
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
