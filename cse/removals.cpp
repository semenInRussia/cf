// semenInRussia 2024
// https://cses.fi/problemset/task/1749
#include <cassert>
#include <iostream>
using namespace std;

const int N = 1 << 18;
int a[N], q[N];
int t[2 * N];

// return k'th one
int qry(int k, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    return l;
  }
  int m = (r + l) / 2;
  if (k <= t[x * 2 + 1]) {
    return qry(k, 2 * x + 1, l, m);
  }
  return qry(k - t[x * 2 + 1], 2 * x + 2, m, r);
}

// mark i as 0
void update(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }
  int m = (r + l) / 2;
  if (i < m) {
    update(i, v, 2 * x + 1, l, m);
  } else {
    update(i, v, 2 * x + 2, m, r);
  }
  t[x] = t[2 * x + 1] + t[2 * x + 2];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    update(i, 1);
  }

  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  // segment tree t[]
  // t[x] - is amount of not removed elements
  // task is to check the real index (in a[]) which must be removed
  for (int i = 0; i < n; i++) {
    int s = q[i];
    int j = qry(s);
    cout << a[j] << ' ';
    update(j, 0);
  }
}
