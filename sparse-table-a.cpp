// Copyright 2023 semenInRussia
//
// https://informatics.msk.ru/mod/statements/view.php?id=597

using namespace std;

#include <iostream>
#include <vector>

using ll = long long;
using pr = pair<ll, size_t>;

vector<vector<pr>> build_sparse(vector<ll> &arr) {
  size_t maxpow = __lg(arr.size());
  size_t n = arr.size();

  vector<vector<pr>> table(maxpow + 1, vector<pr>(n));

  for (size_t i = 0; i < arr.size(); i++) {
    table[0][i] = {arr[i], i};
  }

  for (size_t k = 0; k < maxpow; k++) {
    for (size_t beg = 0; beg + (1 << (1 + k)) <= n; beg++) {
      table[k + 1][beg] = max(table[k][beg], table[k][beg + (1 << k)]);
    }
  }

  return table;
}

int main() {
  size_t n;
  cin >> n;
  vector<ll> arr(n);

  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<vector<pr>> table = build_sparse(arr);

  // for (auto &row : table) {
  //   for (auto &el : row) {
  //     cout << el.first << ' ';
  //   }
  //   cout << endl;
  // }

  size_t m;
  cin >> m;

  for (size_t i = 0; i < m; i++) {
    size_t l, r;
    cin >> l >> r;

    size_t sz;

    if (r == l) {
      sz = 0;
    } else {
      sz = __lg(r - l);
    }

    pr m1 = table[sz][l - 1];
    pr m2 = table[sz][r - (1 << sz)];

    pr m = max(m1, m2);

    cout << m.first << ' ' << m.second + 1 << endl;
  }

  return 0;
}
