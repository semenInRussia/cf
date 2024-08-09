// semenInRussia 2024
// https://cses.fi/problemset/task/1085
#include <cassert>
#include <iostream>
using namespace std;
const int N = 1 << 20;
int t[2 * N];

int find(int k, int x = 0, int l = 0, int r = N) {
  if (t[x] < k)
    return -1;
  if (r - l == 1)
    return l;
  int m = (r + l) / 2;
  int a = 2 * x + 1, b = 2 * x + 2;
  if (k <= t[a])
    return find(k, a, l, m);
  return find(k - t[a], b, m, r);
}

void change(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }
  int m = (r + l) / 2;
  if (i < m)
    change(i, v, 2 * x + 1, l, m);
  else
    change(i, v, 2 * x + 2, m, r);
  t[x] = t[2 * x + 1] + t[2 * x + 2];
}

int main() {
  int n, p;
  cin >> n >> p;
  p++;
  for (int i = 0; i < n; i++)
    change(i, 1);

  int j = 1;
  while (n > 1) {
    j = (j + p - 1) % n;
    if (j == 0)
      j = n;
    int v = find(j);
    cout << 1 + v << ' ';
    change(v, 0);
    n = t[0];
  }

  cout << 1 + find(1);
}
