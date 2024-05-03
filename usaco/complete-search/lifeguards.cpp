#include <bits/stdc++.h>
using namespace std;

int occupied[1000];
pair<int, int> queries[105];

int main() {
  ifstream cin("lifeguards.in");
  ofstream cout("lifeguards.out");
  int n;
  cin >> n;
  for (int q = 0; q < n; q++) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i < r; i++)
      occupied[i]++;
    queries[q] = {l, r};
  }
  int uncovered = count(occupied, occupied + 1000, 0), mn_free = 1000;
  for (int q = 0; q < n; q++) {
    auto [l, r] = queries[q];
    mn_free = min(mn_free, (int)count(occupied + l, occupied + r, 1));
  }
  cout << (1000 - uncovered - mn_free);
}
