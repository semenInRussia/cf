// Copyright 2023 semenInRussia

// B from:
//
// https://codeforces.com/gym/100093

using namespace std;

#include <fstream>
#include <vector>

using Tbl = vector<vector<int>>;
using Query = pair<int, int>;
using ull = unsigned long long;

#define MAX_ARR_SIZE 100'000

vector<int> init_arr() {
  vector<int> arr(MAX_ARR_SIZE);

  for (size_t i = 1; i < MAX_ARR_SIZE; i++) {
    arr[i - 1] = ((i * i) % 12345) + ((i * i * i) % 23456);
  }

  return arr;
}

void rebuild_sparse_min(Tbl &table) {
  size_t n = table[0].size();
  size_t maxpow = __lg(n);
  Tbl d = 3;
  table.resize(100);
  for (size_t k = 0; k <= maxpow; k++) {
    for (size_t b = 0; b + (2 << k) <= n; b++) {
      table[k + 1][b] = min(table[k][b], table[k][b + (1 << k)]);
    }
  }
}

void rebuild_sparse_max(Tbl &table) {
  size_t n = table[0].size();
  size_t maxpow = __lg(n);

  for (size_t k = 0; k <= maxpow; k++) {
    for (size_t b = 0; b + (1 << (k + 1)) <= n; b++) {
      table[k + 1][b] = max(table[k][b], table[k][b + (1 << k)]);
    }
  }
}

int do_q_min(Tbl &table, Query q) {
  size_t sz;

  if (q.first == q.second) {
    sz = 0;
  } else {
    sz = __lg(q.second - q.first);
  }

  return min(table[sz][q.first - 1], table[sz][q.second - (1 << sz)]);
}

int do_q_max(Tbl &table, Query q) {
  size_t sz;

  if (q.first == q.second) {
    sz = 0;
  } else {
    sz = __lg(q.second - q.first);
  }

  return max(table[sz][q.first - 1], table[sz][q.second - (1 << sz)]);
}

int main() {
  vector<int> arr = init_arr();

  size_t n = MAX_ARR_SIZE;
  Tbl max_tbl(__lg(n) + 1, vector<int>(n));
  Tbl min_tbl(__lg(n) + 1, vector<int>(n));

  max_tbl[0] = arr;
  min_tbl[0] = arr;

  rebuild_sparse_min(min_tbl);
  rebuild_sparse_max(max_tbl);

  ifstream fin("rvq.in");
  ofstream fout("rvq.out");

  size_t k;
  fin >> k;

  for (size_t i = 0; i < k; i++) {
    Query q;
    fin >> q.first >> q.second;

    if (q.first >= 0) {
      int val = do_q_max(max_tbl, q) - do_q_min(min_tbl, q);
      fout << val << endl;
    } else {
      min_tbl[0][-q.first - 1] = q.second;
      max_tbl[0][-q.first - 1] = q.second;
      // TODO: don't build *WHOLE* sparse table
      rebuild_sparse_min(min_tbl);
      rebuild_sparse_max(max_tbl);
    }
  }

  return 0;
}
