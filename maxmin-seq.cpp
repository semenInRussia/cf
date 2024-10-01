// semenInRussia 2024
#include <iostream>
#include <queue>
#include <set>
using namespace std;

const int N = 4e5;
int a[N], b[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<int> rest;
  for (int i = 0; i < n; i++) {
    rest.insert(a[i]);
  }

  int z = 1;
  int cnt = 0;
  int j = 0;
  priority_queue<pair<int, int>> mn, mx;

  for (int i = 0; i < n && !rest.empty(); i++) {
    if (!rest.count(a[i])) {
      continue;
    }
    mn.push({-a[i], -i});
    mx.push({+a[i], -i});
    if (rest.count(a[i]) == 1) {
      while (rest.count(a[i])) {
        priority_queue<pair<int, int>> &cur = (z == 0 ? mn : mx);
        auto [x, i] = cur.top();
        x = abs(x);
        i = -i;
        cur.pop();
        if (i < j || !rest.count(x)) {
          continue;
        }
        b[cnt++] = x;
        z ^= 1;
        j = i + 1;
        rest.erase(x);
      }
      continue;
    }
    rest.erase(rest.find(a[i]));
  }

  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
