// semenInRussia 2024
// https://cses.fi/problemset/task/1676
#include <iostream>
#include <set>
using namespace std;

const int N = 2e5;
int p[N], sz[N];

int get(int x) {
  if (p[x] == x) {
    return x;
  }
  return p[x] = get(p[x]);
}

multiset<int> s;

void join(int a, int b) {
  // sizeA, sizeB
  if (sz[a] > sz[b]) {
    swap(a, b);
  }
  p[a] = b;
  s.erase(s.find(sz[b]));
  s.erase(s.find(sz[a]));
  sz[b] += sz[a];
  s.insert(sz[b]);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
    s.insert(1);
  }
  int cnt = n;
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    a = get(a);
    b = get(b);
    if (a != b) {
      join(a, b);
      cnt--;
    }
    cout << cnt << ' ' << *s.rbegin() << '\n';
  }
}
