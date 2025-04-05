// semenInRussia 2024
#include <iostream>
#include <map>
#include <vector>
using namespace std;

using ll = long long;

const int N = 3e5;
vector<int> g[N];

int a[N];
bool ok[N];
int p[N];
ll sum[N];

pair<int, bool> get(int x) {
  if (p[x] == x) {
    return {x, ok[x]};
  }
  auto v = get(p[x]);
  p[x] = v.first;
  ok[x] &= v.second;
  return {p[x], ok[x]};
}

void join(int x, int y) {
  x = get(x).first;
  y = get(y).first;

  if (x == y) {
    return;
  }

  if (!ok[y]) {
    swap(x, y);
  }

  p[x] = y;
  sum[y] += sum[x];
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 0; i < n; i++) {
    p[i] = i;
    ok[i] = 1;
    sum[i] = a[i];
  }

  map<int, vector<int>> mp;

  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(i);
  }

  for (auto [v, xs] : mp) {
    for (int x : xs) {
      for (int y : g[x]) {
        if (a[y] > v) {
          continue;
        }
        if (sum[get(y).first] < v) {
          ok[get(y).first] = 0;
        }
        join(x, y);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << get(i).second;
  }
}
