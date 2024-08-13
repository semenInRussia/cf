// semenInRussia 2024
// https://cses.fi/problemset/task/1164
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9;

const int N = 2e5;
pii p[N], _p[N];

int main() {
  int n;
  cin >> n;
  multiset<pii> hotel; // departure time, room number
  hotel.insert({-1, -1});
  map<pii, vector<int>> ans;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    _p[i] = p[i] = {a, b};
  }
  sort(p, p + n);

  for (int i = 0; i < n; i++) {
    int a = p[i].first, b = p[i].second;
    int num = -1; // number of room
    auto it = prev(hotel.lower_bound({a, -inf}));
    if (it == hotel.end() || it->first == -1) {
      num = hotel.size() + 1;
      hotel.insert({b, num});
    } else {
      auto p = *it;
      num = p.second;
      hotel.erase(p);
      hotel.insert({b, num});
    }
    ans[{a, b}].push_back(num);
  }
  swap(_p, p);
  cout << hotel.size() << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[p[i]].back() << ' ';
    ans[p[i]].pop_back();
  }
}
