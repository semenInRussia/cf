// semenInRussia 2024
#include <iostream>
#include <list>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

#pragma GCC optimize("Ofast,unroll-loops")

const int N = 1.1e5, C = 1600, G = (2 * N) / C + 5;
list<int> b[G]; // every integer is { size of area }

// try to keep size=C of every b[g]
void resize(int g) {
  for (; g < G && !b[g].empty(); g++) {
    while (int(b[g].size()) > C) {
      int d = b[g].back();
      b[g].pop_back();
      b[g + 1].push_front(d);
    }
    while (int(b[g].size()) < C) {
      if (b[g + 1].empty())
        break;
      int d = b[g + 1].front();
      b[g + 1].pop_front();
      b[g].push_back(d);
    }
  }
}

ll ans = 0;
void update(int e, int g, int j) {
  if (e == 1) {
    int i = 0;
    for (auto it = b[g].begin(); it != b[g].end(); it++, i++) {
      if (i == j) {
        int d = *it;
        ans -= 1ll * d * d;
        if (i == 0 || i == b[g].size() - 1) {
          // remove it, give to prev/next
          auto jt = i ? prev(it) : next(it);
          ans -= 1ll * *jt * *jt;
          *jt += d;
          ans += 1ll * *jt * *jt;
          b[g].erase(it);
          break;
        }
        int a1 = d / 2, a2 = (d + 1) / 2;
        auto prv = prev(it), nxt = next(it);
        b[g].erase(it);
        ans -= 1ll * *prv * *prv;
        ans -= 1ll * *nxt * *nxt;
        *prv += a1, *nxt += a2;
        ans += 1ll * *prv * *prv;
        ans += 1ll * *nxt * *nxt;
        break;
      }
    }
  } else {
    int i = 0;
    // split to 2
    for (auto it = b[g].begin(); it != b[g].end(); it++, i++) {
      if (i == j) {
        int d = *it;
        int a1 = d / 2, a2 = (d + 1) / 2;
        ans += 1ll * a2 * a2;
        ans += 1ll * a1 * a1;
        *it = a2;
        b[g].insert(it, a1);
        ans -= 1ll * d * d;
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr), cout.tie(nullptr);
  freopen("river.in", "r", stdin);
#ifdef ONLINE_JUDGE
  freopen("river.out", "w", stdout);
#endif
  //--

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
    for (; g < G && !(v >= sm && v < sm + b[g].size()); g++)
      sm += (int)b[g].size();
    if (g && v == sm) {
      // from b[g - 1] to b[g]
      int ai = b[g - 1].back();
      b[g - 1].pop_back();
      b[g].push_front(ai);
      sm--;
    }
    if (!b[g + 1].empty() && v == sm + (int)b[g].size() - 1) {
      // from b[g + 1] to b[g]
      int ai = b[g + 1].front();
      b[g + 1].pop_front();
      b[g].push_back(ai);
    }
    update(e, g, v - sm);
    resize(max(0, g - (v == sm + 1)));
    cout << ans << '\n';
  }
}
