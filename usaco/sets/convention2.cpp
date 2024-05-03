// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct Cow {
  int a, t, id;
};

// for set<Cow> right ordering
struct by_id {
  bool operator()(const Cow &a, const Cow &b) const { return a.id < b.id; }
};
struct by_a {
  bool operator()(const Cow &a, const Cow &b) const { return a.a < b.a; }
};

int main() {
  ifstream cin("convention2.in");
  ofstream cout("convention2.out");

  int n;
  cin >> n;

  vector<Cow> cows(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i].a >> cows[i].t;
    cows[i].id = i + 1;
  }

  multiset<Cow, by_a> qt;
  set<Cow, by_id> qi;
  for (auto cow : cows)
    qt.insert(cow);

  int ans = 0, t = qt.begin()->a;

  while (!qt.empty() || !qi.empty()) {
    if (qi.empty() || (!qt.empty() && qt.begin()->a <= t)) {
      qi.insert(*qt.begin());
      qt.erase(qt.begin());
    } else {
      Cow cur = *qi.begin();
      ans = max(ans, t - cur.a);
      t = max(t, cur.a) + cur.t;
      qi.erase(cur);
      vector<Cow> tokill;
      for (auto cow : qi)
        if (cow.a > t)
          tokill.push_back(cow);
      for (auto cow : tokill)
        qi.erase(cow), qt.insert(cow);
    }
  }

  cout << ans << endl;
}
