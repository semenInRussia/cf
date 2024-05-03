// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

using ull = unsigned long long;

int n, nm, nr;
vector<int> c(n), r(nr);
vector<pair<int, int>> m(nm);

void pop(int k) {
  int i = int(m.size()) - 1;
  while (i >= 0 && k) {
    int sell = min(m[i].second, k);
    k -= sell, m[i].second -= sell;
    i--;
  }
  while (!m.empty() && !m.back().second)
    m.pop_back();
}

int take(int k) {
  if (m.empty())
    return 0;

  int ans = 0, i = int(m.size() - 1);
  while (i >= 0 && k) {
    int sell = min(m[i].second, k);
    k -= sell;
    ans += sell * m[i].first;
    i--;
  }

  return ans;
}

int main() {
  ifstream cin("rental.in");
  ofstream cout("rental.out");
  //
  cin >> n >> nm >> nr;
  c.resize(n), r.resize(nr);
  m.resize(nm);

  for (auto &x : c)
    cin >> x;
  for (auto &x : m)
    cin >> x.second >> x.first;
  for (auto &x : r)
    cin >> x;

  sort(c.begin(), c.end());
  sort(m.begin(), m.end());
  sort(r.rbegin(), r.rend());

  ull ans = 0;

  for (int i = n - 1; i >= 0; i--) {
    int ci = c[i];
    int rent = r.empty() ? 0 : r.back();
    int sell = take(ci);
    if (rent >= sell)
      ans += rent, r.pop_back();
    else
      ans += sell, pop(ci);
  }

  cout << ans << endl;
}
