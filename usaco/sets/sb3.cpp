// Copyright 2018 Daniel Ilozor

#include <bits/stdc++.h>
using namespace std;

// This is similar to CSES Traffic Lights, Try solving that problem in
// order to understand this approach The idea is to sort the boots in
// order of increasing depth and "unlock" cells as we go through each
// boot then store maximum distance between two adjacent "unlocked"
// cells and check if its less than distance of boot
const int maxn = 1e5 + 10;
int n, m, ans[maxn];
pair<pair<int, int>, int> v[maxn];
multiset<pair<int, int>> a;

int main() {
  ifstream cin("snowboots.in");
  ofstream cout("snowboots.out");
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i and i != n - 1)
      // store depth and index of all currently unavailable cells
      a.insert({x, i});
  }
  for (int i = 0; i < m; i++) {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i; // remember original index
  }
  sort(v, v + m); // sort by depth
  set<int> S;     // stores all available cells

  // dist stores all distances between two unlocked adjacent cells in
  // decreasing order
  multiset<int, greater<int>> dist;
  S.insert(0), S.insert(n - 1);
  dist.insert(n - 1); // first and last cells are available on the get-go

  for (int i = 0; i < m; i++) {
    int s = v[i].first.first, d = v[i].first.second;
    while (!a.empty()) // checks for cells that can become unlocked if using
                       // current boot
    {
      auto beg = *a.begin();
      if (beg.first > s)
        break; // if no new cells can become unlocked with new boots due to
               // depth, stop
      int j = (*a.begin()).second;
      // itr points to index of cell just before current cell index in the set
      // it2 points to index of cell just after current cell index in the set
      auto itr = S.lower_bound(j);
      itr--;
      auto itr2 = S.lower_bound(j);
      int Dis = *itr2 - *itr;
      S.insert(j); // add new cell in-between itr and itr2, now distance is
                   // shortened so update them
      dist.erase(dist.find(Dis)); // remove old distance
      // add the new distances
      dist.insert(j - *itr);
      dist.insert(*itr2 - j);
      a.erase(a.begin()); // remove cell since its now unlocked
    }
    // if max distance between two unlocked cells <= reachable distance of
    // current boot, boot can go through
    ans[v[i].second] = (*dist.begin() <= d);
  }
  for (int i = 0; i < m; i++)
    cout << ans[i] << "\n";
}
