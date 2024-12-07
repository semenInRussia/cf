// semenInRussia 2024
// Disjoin System Union (DSU), very usable thing
#include <iostream>
#include <vector>
using namespace std;

struct dsu {
  vector<int> p, sz;

  dsu(int n) { clear(n); }

  // k - new size, maybe (-1 - no change)
  void clear(int k = -1) {
    if (k == -1) {
      k = int(p.size());
    }
    p.resize(k);
    sz.assign(k, 1);
    for (int i = 0; i < k; i++) {
      p[i] = i;
    }
  }

  inline void resize(int k) { clear(k); }

  int get(int i) {
    if (p[i] == i) {
      return i;
    }
    return p[i] = get(p[i]);
  }

  int join(int a, int b) {
    b = get(b);
    a = get(a);
    if (sz[b] > sz[a]) {
      swap(a, b);
    }
    sz[a] += sz[b];
    return p[b] = a;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  int n, m;
  cin >> n >> m;
  dsu ds(n);
  for (int i = 0; i < m; i++) {
    string t;
    int a, b;
    cin >> t >> a >> b;
    a--, b--;
    if (t == "union") {
      ds.join(a, b);
    } else {
      bool ok = ds.get(a) == ds.get(b);
      cout << (ok ? "YES" : "NO") << "\n";
    }
  }
}
