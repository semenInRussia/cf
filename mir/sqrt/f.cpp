// semenInRussia 2024
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define isz(a) int((a).size())

#pragma GCC optimize("Ofast,unroll-loops")

const int N = 1.001e5, C = 1700, G = (2 * N) / C + 5;
vector<int> b[G]; // every integer is { size of area }

// try to keep size=C of every b[g]
void resize(int g) {
  for (; g < G && !b[g].empty(); g++) {
    while (isz(b[g]) > C) {
      int d = b[g].back();
      b[g].pop_back();
      b[g + 1].insert(b[g + 1].begin(), d);
    }
    while (isz(b[g]) < C && !b[g + 1].empty()) {
      int d = b[g + 1].front();
      b[g + 1].erase(b[g + 1].begin());
      b[g].push_back(d);
    }
  }
}

ll ans = 0;

void update(int e, int g, int j) {
  auto it = b[g].begin() + j;
  assert(it != b[g].end());
  int d = *it;
  if (e == 2) {
    // split on 2
    ans -= 1ll * d * d;
    int a1 = d / 2, a2 = (d + 1) / 2;
    ans += 1ll * a2 * a2;
    ans += 1ll * a1 * a1;
    *it = a2;
    b[g].insert(it, a1);
    return;
  }
  // remove it, split for neighbors
  ans -= 1ll * d * d;
  if (j == 0 || j == isz(b[g]) - 1) {
    // only one neighbor
    auto jt = j ? prev(it) : next(it);
    ans -= 1ll * *jt * *jt;
    *jt += d;
    ans += 1ll * *jt * *jt;
    b[g].erase(it);
    return;
  }
  int a1 = d / 2, a2 = (d + 1) / 2;
  auto prv = prev(it), nxt = next(it);
  ans -= 1ll * *prv * *prv;
  ans -= 1ll * *nxt * *nxt;
  *prv += a1, *nxt += a2;
  ans += 1ll * *prv * *prv;
  ans += 1ll * *nxt * *nxt;
  b[g].erase(it);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr), cout.tie(nullptr);
  freopen("river.in", "r", stdin);
#ifdef ONLINE_JUDGE
  freopen("river.out", "w", stdout);
#endif

  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    ans += 1ll * ai * ai;
    b[i / C].push_back(ai);
  }

  cout << ans << '\n';
  int q;
  cin >> q;
  while (q--) {
    int e, v;
    cin >> e >> v;
    v--;
    int g = 0, sm = 0;
    // block g:
    // [sm; sm + sz)
    for (; g < G && !(v >= sm && v < sm + isz(b[g])); g++)
      sm += isz(b[g]);
    if (g && v == sm) {
      // from b[g - 1] to b[g]
      int ai = b[g - 1].back();
      b[g - 1].pop_back();
      b[g].insert(b[g].begin(), ai);
      sm--;
    } else if (!b[g + 1].empty() && v == sm + isz(b[g]) - 1) {
      // from b[g + 1] to b[g]
      ll ai = b[g + 1].front();
      b[g + 1].erase(b[g + 1].begin());
      b[g].push_back(ai);
    }
    update(e, g, v - sm);
    resize(max(0, g - 1));
    cout << ans << '\n';
  }
}
