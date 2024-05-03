// Copyright 2023 semenInRussia

// C from:
//
// https://codeforces.com/gym/100093

using namespace std;

#include <fstream>
#include <vector>

#define MIN(a, b) a > b ? b : a

void build(vector<size_t> &t, vector<size_t> &arr, size_t start);
size_t do_query(vector<size_t> &t, size_t l, size_t r);
void assign(vector<size_t> &arr, size_t l, size_t r, size_t x);

int main() {
  ifstream fin("sum.in");
  ofstream fout("sum.out");

  fin.tie();
  fout.tie();
  fin.sync();

  size_t n, k;
  fin >> n >> k;

  vector<size_t> arr(n);
  vector<size_t> table(n + 1);

  table[0] = 0;

  bool is_assign = false;
  size_t min_assign_index = -1;
  char kind;
  size_t l, r, x;

  for (size_t i = 0; i < k; i++) {
    fin >> kind;

    if (kind == 'Q') {
      fin >> l >> r;
      if (is_assign) {
        build(table, arr, min_assign_index);
        is_assign = false;
        min_assign_index = -1;
      }
      fout << do_query(table, l, r) << '\n';
    } else {
      fin >> l >> r >> x;
      is_assign = true;
      min_assign_index = MIN(min_assign_index, l);
      assign(arr, l, r, x);
    }
  }

  return 0;
}

void build(vector<size_t> &t, vector<size_t> &arr, size_t start) {
  for (size_t i = start - 1; i < arr.size(); i++) {
    t[i + 1] = t[i] + arr[i];
  }
}

inline size_t do_query(vector<size_t> &t, size_t l, size_t r) {
  // do_query
  return t[r] - t[l - 1];
}

void assign(vector<size_t> &arr, size_t l, size_t r, size_t x) {
  for (size_t i = l; i <= r; i++) {
    arr[i - 1] = x;
  }
}
