// semenInRussia 2025
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #define HOME

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type,
             less<pair<long long, long long>>, rb_tree_tag,
             tree_order_statistics_node_update>
    stree;

const long long inf = 1e9 + 100;

struct hld {
  stree v;
  long long t = 0;

  hld() { t = 0; }

  void add(long long x) { v.insert({x, t++}); }
  void er(long long x) { v.erase(v.lower_bound({x, 0})); }

  int nth(int i) { return v.find_by_order(i)->first; }
};

int main() {
  freopen("kthmax.in", "r", stdin);
  freopen("kthmax.out", "w", stdout);
  int n;
  cin >> n;

  hld h;

  int sz = 0;

  for (int i = 0; i < n; i++) {
    int typ;
    cin >> typ;
    int x;
    cin >> x;
    if (typ == -1) {
      h.er(x);
      sz--;
    } else if (typ == +1) {
      h.add(x);
      sz++;
    } else {
      cout << h.nth(sz - x) << "\n";
    }
  }
}
