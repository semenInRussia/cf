// semenInRussia 2024
// https://contest.yandex.ru/contest/69757/problems/F/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define isz(x) int((x).size())

const int N = 6e5;
int p[N];
int64_t a[N];

int get(int i) {
  if (p[i] == i) {
    return i;
  }
  return p[i] = get(p[i]);
}

int join(int a, int b) { return p[b] = a; }

// v[x] - top values of x group
vector<int64_t> v[N];

const int K = 25;

void join2(int x, int y) {
  x = get(x);
  y = get(y);
  int i = join(x, y);
  for (auto t : v[x + y - i]) {
    v[i].push_back(t);
  }
  sort(v[i].rbegin(), v[i].rend());
  v[i].resize(min(K, isz(v[i])));
}

void erase(int x) {
  auto &row = v[get(x)];
  auto it = find(row.begin(), row.end(), a[x]);
  if (it != row.end()) {
    row.erase(it);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[i].push_back(a[i]);
  }

  int q;
  cin >> q;
  while (q--) {
    int typ, x, y;
    cin >> typ >> x;
    x--;
    if (typ == 1) {
      erase(x);
    } else if (typ == 2) {
      cin >> y;
      y--;
      if (get(x) != get(y)) {
        join2(x, y);
      }
    } else {
      auto &row = v[get(x)];
      for (int j = 2; j >= 0; j--) {
        cout << (j < isz(row) ? row[j] : -1) << ' ';
      }
      cout << "\n";
    }
  }
}
