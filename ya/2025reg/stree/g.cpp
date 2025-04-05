// semenInRussia 2024
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct cord {
  int l;
  int r;
  int x;
  int id;

  cord() {};
};

bool compare(cord a, cord b) {
  return ((a.x > b.x) || ((a.x == b.x) && (a.id < b.id)));
}

int get(vector<int> &dsu, int v) {
  if (dsu[v] == v)
    return v;
  dsu[v] = get(dsu, dsu[v]);
  return dsu[v];
}

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> dsu(n + 1);
  vector<int> ans(n, INT_MAX);
  vector<int> lg(n + 1);
  vector<vector<int>> table(n, vector<int>(17));

  lg[1] = 0;
  if (n > 1) {
    lg[2] = 1;
  }

  for (int i = 3; i <= n; i++) {
    lg[i] = (i & (i - 1)) ? lg[i - 1] : lg[i - 1] + 1;
  }

  vector<cord> a(q);

  for (int i = 0; i <= n; i++) {
    dsu[i] = i;
  }

  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    a[i].l = l - 1;
    a[i].r = r - 1;
    a[i].x = x;
    a[i].id = i;
  }

  sort(a.begin(), a.end(), compare);
  for (int i = 0; i < q; i++) {
    int l = a[i].l;
    int r = a[i].r;
    int x = a[i].x;
    for (int j = get(dsu, l); j <= r; j = get(dsu, j)) {
      dsu[j] = j + 1;
      ans[j] = x;
    }
  }

  for (int i = 0; i < n; i++)
    table[i][0] = ans[i];

  for (int j = 1; j < 17; j++)
    for (int i = 0; i < n; i++)
      if (i + (1 << (j - 1)) < n)
        table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      else
        table[i][j] = min(table[i][j - 1], INT_MAX + 1);

  auto qry = [&](int l, int r) {
    return min(table[l][lg[r - l + 1]],
               table[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
  };

  for (int i = 0; i < q; i++) {
    int l = a[i].l;
    int r = a[i].r;
    int x = a[i].x;
    if (qry(l, r) != x) {
      cout << "inconsistent" << endl;
      return 0;
    }
  }

  cout << "consistent" << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
}
