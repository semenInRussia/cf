// semenInRussia 2023

// solution of 1922/D problem from the codeforces.com
// https://codeforces.com/contest/1922/problem/D

using namespace std;

#include <climits>
#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

struct monster {
  int a;
  int d;
  size_t i;
};

using node = list<monster>::iterator;
#define INF INT_MAX

void solve() {
  size_t n;
  cin >> n;

  vector<int> a(n);
  vector<int> d(n);
  
  for (auto &x : a)
    cin >> x;

  for (auto &x : d)
    cin >> x;

  list<monster> l;
  l.push_back({0, INF});
  for (size_t i = 0; i < n; i++) {
    l.push_back({a[i], d[i]});
  }
  l.push_back({0, INF});

  vector<node> cur;
  node it = l.begin();
  it++;

  for (size_t i = 0; i < n; i++) {
    cur.push_back(it);
    it++;
  }

  size_t i = 0;
  for (auto &m : l) {
    m.i = i++;
  }

  unordered_set<size_t> all_del;

  for (size_t z = 0; z < n; z++) {
    vector<node> ncur;
    unordered_set<size_t> ncur_i;

    vector<node> del;
    unordered_set<size_t> del_i;

    for (auto m : cur) {
      if (!m->a || all_del.count(m->i))
        continue;

      node prv = prev(m);
      node nxt = next(m);

      if (prv->a + nxt->a > m->d) {
        if (!ncur_i.count(nxt->i)) {
          ncur_i.insert(nxt->i);
          ncur.push_back(nxt);
        }

        if (!ncur_i.count(prv->i)) {
          ncur.push_back(prv);
          ncur_i.insert(prv->i);
        }

        if (!del_i.count(m->i)) {
          del.push_back(m);
          del_i.insert(m->i);
        }
      }
    }

    cur = std::move(ncur);

    for (size_t i = 0; i < del.size(); i++) {
      l.erase(m);
      all_del.insert(m->i);
    }

    cout << del.size() << ' ';
  }

  cout << endl;
}

int main() {
  size_t t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
