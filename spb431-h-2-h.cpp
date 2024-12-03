// решаю задачу H с отбора на ВКОШП 2024, Европейская часть

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>
//
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 2e5;
// multiset<pair<int, int>> g[N];
multiset<int> cg[N];

int cntbad[N]; // count "bad" vertexes
int cnt[N];

int ans = 0;

bool good(int x, int c) { // when remove
  return cg[x].count(c) == 2;
}

bool bad(int x, int c) { // when add
  return cg[x].count(c) == 1;
}

void add(int x, int y, int c) {
  bool vx = bad(x, c);
  bool vy = bad(y, c);

  if ((vx || vy) && cntbad[c] == 0) {
    ans -= cnt[c];
  }
  cntbad[c] += vx;
  cntbad[c] += vy;
  cnt[c]++;

  cg[x].insert(c);
  cg[y].insert(c);

  if (cg[x].count(c) <= 1 && cg[y].count(c) <= 1 && cntbad[c] == 0) {
    ans++;
  }
}

void rem(int x, int y, int c) {
  bool vx = good(x, c);
  bool vy = good(y, c);

  cntbad[c] -= vx;
  cntbad[c] -= vy;

  if (cntbad[c] == 0 && (vx || vy)) {
    ans += cnt[c] - 1;
  } else if (cntbad[c] == 0) {
    ans--;
  }

  cnt[c]--;

  cg[x].erase(cg[x].find(c));
  cg[y].erase(cg[y].find(c));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int z = 0; z < q; z++) {
    char typ;
    cin >> typ;
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;

    if (typ == '+') {
      add(a, b, c);
    } else {
      rem(a, b, c);
    }
    cout << ans << '\n';
  }
}
