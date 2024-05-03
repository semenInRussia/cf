// Copyright 2023 semenInRussia

using namespace std;

#include <cstdlib>
#include <fstream>
#include <vector>

#define TEST
#define UPDATE 1
#define QUERY 2

// print("\n".join(map(lambda a, b: f"{bin(a)[2:]}: {b}", range(0, 100), [2, 2,
// 4, 4, 4, 2, 4, 8, 2, 2])))

using ul = unsigned long long;

ul xor_query(vector<ul> &a, size_t l, size_t r, size_t k) noexcept;
void xor_assign(vector<ul> &a, size_t l, size_t r, size_t k, ul v);
ul query(vector<ul> &a, size_t l, size_t r);
void assign(vector<ul> &a, size_t i, ul x);

#ifdef TEST

#include <iostream>

int main() {
  vector<ul> t{1, 2, 3, 4, 5, 6, 7, 8};

  size_t n = 8;
  vector<ul> a(2 * n);

  for (size_t i = 0; i < n; i++) {
    a[n + i] = t[i];
  }

  for (size_t i = n - 1; i > 0; --i) {
    a[i] = a[2 * i] + a[(2 * i) | 1];
  }

  for (size_t l = 0; l < n; l++) {
    for (size_t r = l; r < n; r++) {
      for (size_t k = 0; k < n; k++) {
        ul expected{0};

        // if (rand() > (RAND_MAX / 2)) {
        //   size_t v = rand() / 1000;

        //   cout << "ch: " << l << " to " << r << " on " << v << endl;

        //   for (size_t i = l; i <= r; i++) {
        //     assign(a, i ^ k, v);
        //     t[i ^ k] = v;
        //   }
        // }

        for (size_t i = l; i <= r; i++) {
          expected += t[i ^ k];
        }

        ul actual = xor_query(a, l, r, k);

        if (expected != actual) {
          cout << "l, r, k = " << l << ", " << r << ", " << k << endl;
          actual = xor_query(a, l, r, k);

          cout << "NO: ";
          cout << expected << " == " << actual << endl;
        } else {
          cout << ".";
        }
      }
    }
  }

  return 0;
}

#else

int main() {
  ofstream fout("output.txt");
  ifstream fin("input.txt");

  size_t d;
  fin >> d;

  size_t n = 1 << d;

  vector<ul> a(2 * n);

  for (size_t i = 0; i < n; i++) {
    fin >> a[n + i];
  }

  for (size_t i = n - 1; i > 0; --i) {
    a[i] = a[2 * i] + a[(2 * i) | 1];
  }

  size_t q;
  fin >> q;

  for (size_t j = 0; j < q; j++) {
    int typ;
    ul l, r, k;
    fin >> typ >> l >> r >> k;

    if (typ == QUERY) {
      fout << xor_query(a, l, r, k) << endl;
    } else {
      ul v;
      fin >> v;
      xor_assign(a, l, r, k, v);
    }
  }
  return 0;
}

#endif

void assign(vector<ul> &a, size_t l, size_t r, ul value) {
  for (size_t i = l; i < r; i++) {
    assign(a, i, value);
  }
}

void assign(vector<ul> &a, size_t i, ul x) {
  size_t n = a.size() / 2;
  i += n;

  for (a[i] = x; i > 1; i >>= 1) {
    a[i >> 1] = a[i] + a[i ^ 1];
  }
}

ul xor_query(vector<ul> &a, size_t r, size_t k) {
  // step 1:
  // if r is (2^d-1), then result is query(0,r)
  size_t sz = 2 << __lg(k);
  if ((r + 1) % sz == 0) {
    return query(a, 0, r + 1);
  }

  size_t rr = sz * ((rr + sz) / sz) - 1;
  ul result = query(a, 0, rr + 1);
  size_t n = a.size() / 2;

  // - (r, rr]
  for (size_t i = r + 1; i <= rr; i++) {
    result -= a[n + (i ^ k)];
  }

  return result;
}

ul xor_query(vector<ul> &a, size_t l, size_t r, size_t k) noexcept {
  if (l == 0) {
    return xor_query(a, r, k);
  } else {
    return xor_query(a, r, k) - xor_query(a, l - 1, k);
  }
}

void xor_assign(vector<ul> &a, size_t l, size_t r, size_t k, ul v) {
  for (size_t i = l; i <= r; i++) {
    assign(a, i ^ k, v);
  }
}

ul query(vector<ul> &a, size_t l, size_t r) {
  ul res = 0;
  size_t n = a.size() / 2;

  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l & 1) {
      res += a[l++];
    }
    if (r & 1) {
      res += a[--r];
    }
  }

  return res;
}
