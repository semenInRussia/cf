// semenInRussia 2024
// https://cses.fi/problemset/task/1143
#include <iostream>
using namespace std;

const int N = 1 << 18;
int r[N], h[N];
int t[2 * N]; // max

// find the left i, h[i] >= v
int qry(int v, int x = 0, int l = 0, int r = N) {
  if (t[x] < v) {
    return -1;
  }
  if (r - l == 1) {
    return l;
  }
  int m = (r + l) / 2;
  if (v <= t[2 * x + 1]) {
    return qry(v, 2 * x + 1, l, m);
  }
  return qry(v, 2 * x + 2, m, r);
}

void update(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    h[i] = v;
    return;
  }
  int m = (r + l) / 2;
  if (i < m) {
    update(i, v, 2 * x + 1, l, m);
  } else {
    update(i, v, 2 * x + 2, m, r);
  }
  t[x] = max(t[2 * x + 1], t[2 * x + 2]);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    update(i, h[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> r[i];
  }

  // for every group:
  // - find the left hotel (h[i] >= r[i])
  // - h[i] -= r[i]
  for (int i = 0; i < m; i++) {
    int j = qry(r[i]);
    cout << (j + 1) << ' ';
    if (j >= 0) {
      update(j, h[j] - r[i]);
    }
  }
}
