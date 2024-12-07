// semenInRussia 2024
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

struct dsu {
  vector<int> p;

  dsu(int n) {
    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  void join(int a, int b) { p[b] = a; }
  int get(int a) {
    if (p[a] == a) {
      return a;
    }
    p[a] = get(p[a]);
    return p[a];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  dsu ds(n);
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (t == "union") {
      ds.join(a, b);
    } else {
      bool ok = ds.get(a) == ds.get(b);
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
}
