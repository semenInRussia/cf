// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct fenw {
  int n;
  vector<int> t;

  fenw(int _n) : n(_n) { t.resize(n + 1); }

  // t[i] += v
  void add(int i, int v) {
    i++;
    for (; i <= n; i += i & -i) {
      t[i] += v;
    }
  }

  // sum t[0; i)
  int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) {
      s += t[i];
    }
    return s;
  }

  // find k; t[0; i)=k
  //
  // lower_bound(x) return first i; sum[0; i] >= x
  int lower_bound(int x) {
    // find last i; sum[0;i) < x
    int k = 0;
    for (int l = __lg(n) + 1; l >= 0; l--) {
      if (k + (1 << l) <= n && t[k + (1 << l)] < x) {
        k += 1 << l;
        x -= t[k];
      }
    }
    return k;
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  fenw t(n);

  for (int i = 1; i < n; i++) {
    t.add(i, +1);
  }

  // join(i); join block i and i+1
  // get(i); get L and R bounds of i'th block

  int sz = n; // amount of blocks

  auto get = [&](int i) -> pair<int, int> {
    int l = t.lower_bound(i);
    int r = t.lower_bound(i + 1);
    return {l, r};
  };

  // join i, i+1
  auto join = [&](int i) {
    auto [l, r] = get(i); //
    t.add(r, -1);
    sz--;
  };

  auto display = [&]() {
    for (int i = 0; i < sz; i++) {
      auto [l, r] = get(i);
      cout << "[" << l << "; " << r << ") ";
    }
    cout << "\n";
  };

  display();

  while (q--) {
    char c;
    cin >> c;

    if (c == 'j') {
      int j;
      cin >> j;
      join(j);
    } else {
      int j;
      cin >> j;
      auto [l, r] = get(j);
      cout << "[" << l << "; " << r << ")\n";
    }

    display();
  }
}
