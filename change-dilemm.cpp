// semenInRussia 2024
// https://codeforces.com/problemset/problem/1984/D
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5;
using pii = pair<int, int>;
pii a[N], b[N];
// int ord1[N], ord2[N];
int t1[N], t2[N];
int n;
int qry(const int t[N], int r) { // sum [1; r)
  int ans = 0;
  for (; r > 0; r -= r & -r)
    ans += t[r];
  return ans;
}
inline void add(int t[N], int k, const int v) {
  for (; k <= n; k += k & -k)
    t[k] += v;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < n; i++)
      cin >> b[i].first, b[i].second = i;

    sort(a, a + n, [](auto a, auto b) { return a.first < b.first; });
    sort(b, b + n, [](auto a, auto b) { return a.first < b.first; });
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (a[i].first != b[i].first) {
        ans = false;
        break;
      }
    }

    int A = 0, B = 0;
    if (!ans)
      goto end;

    fill(t1, t1 + n + 1, 0);
    fill(t2, t2 + n + 1, 0);
    for (int i = 0; i < n; i++) {
      const int x = a[i].second + 1; // zero nUt supported
      A += abs(qry(t1, x) + a[i].second - i);
      add(t1, x, 1);

      const int y = b[i].second + 1;
      B += abs(qry(t2, y) + b[i].second - i);
      add(t2, y, 1);
    }
    ans &= ~(A - B) & 1;
  end:
    cout << (ans ? "YES\n" : "NO\n");
  }
}
