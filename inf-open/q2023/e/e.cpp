// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t n, m, k;
  cin >> n >> m >> k;

  vector<size_t> cols(m + 1);
  vector<size_t> count_cols(k + 1);

  for (size_t i = 1; i <= m; i++) {
    size_t _x, _y, col;
    cin >> _x >> _y >> col;
    cols[i] = col;
    count_cols[col]++;
  }

  size_t q;
  cin >> q;

  while (q--) {
    size_t i, new_col;
    cin >> i >> new_col;

    // if (m < n - 1) {
    //   cout << "No" << endl;
    //   continue;
    // }

    count_cols[cols[i]]--;
    count_cols[new_col]++;
    cols[i] = new_col;

    if (k == 1 && m != 0) {
      cout << "Yes" << endl;
      continue;
    }

    if (!m) {
      cout << "No" << endl;
      continue;
    }

    if (find(count_cols.begin() + 1, count_cols.end(), 0) == end(count_cols)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
