// Copyright 2023 semenInRussia

// "A" from the contest:
//
// https://codeforces.com/gym/100093

using namespace std;

#include <fstream>
#include <vector>

using ll = long long;

vector<vector<ll>> build_sparse(vector<ll> &arr) {
  size_t n = arr.size();
  size_t maxpow = __lg(n);

  vector<vector<ll>> table(maxpow + 1, vector<ll>(n));
  table[0] = arr;

  for (size_t k = 0; k < maxpow; k++) {
    for (size_t b = 0; b + (1 << (1 + k)) <= n; b++) {
      table[k + 1][b] = min(table[k][b], table[k][b + (1 << k)]);
    }
  }

  return table;
}

int main() {
  std::ifstream fin("stupid_rmq.in");
  std::ofstream fout("stupid_rmq.out");

  size_t n;
  fin >> n;
  vector<ll> arr(n);

  for (size_t i = 0; i < n; i++) {
    fin >> arr[i];
  }

  vector<vector<ll>> table = build_sparse(arr);

  size_t q;
  fin >> q;

  for (size_t i = 0; i < q; i++) {
    size_t l, r;

    fin >> l >> r;
    size_t sz;

    if (l == r) {
      sz = 0;
    } else {
      sz = __lg(r - l);
    }

    fout << min(table[sz][l - 1], table[sz][r - (1 << sz)]) << endl;
  }

  return 0;
}
