// Copyright 2023 semenInRussia

using namespace std;

#include <cstdlib>
#include <fstream>
#include <vector>

#define UPDATE 1
#define QUERY 2

// print("\n".join(map(lambda a, b: f"{bin(a)[2:]}: {b}", range(0, 100), [2, 2,
// 4, 4, 4, 2, 4, 8, 2, 2])))

using ul = unsigned long long;

ul xor_query(vector<ul> &a, size_t l, size_t r, size_t k, bool straight);
void xor_assign(vector<ul> &a, size_t l, size_t r, size_t k, ul v,
                bool straight);
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

        ul actual = xor_query(a, l, r, k, false);

        if (expected != actual) {
          cout << "l, r, k = " << l << ", " << r << ", " << k << endl;
          actual = xor_query(a, l, r, k, false);

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
      fout << xor_query(a, l, r, k, false) << endl;
    } else {
      ul v;
      fin >> v;
      xor_assign(a, l, r, k, v, false);
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

ul xor_query(vector<ul> &a, size_t l, size_t r, size_t k, bool straight) {
  size_t n = a.size() / 2;

  if (l == r) {
    return a[n + (l ^ k)];
  }

  size_t chnk = 2 << __lg(k);
  chnk = chnk == 0 ? 1 : chnk;

  bool inside_chunks = l % chnk == 0 && (r + 1) % chnk == 0;

  if (k == 0 || inside_chunks) {
    return query(a, l, r + 1);
  }

  // x : x >= l, x % chnk == 0
  size_t l2 = (l % chnk == 0) ? l : l + chnk - l % chnk;
  // x : x <= r, x % chnk == 0
  size_t r2 = ((r + 1) % chnk == 0) ? r : r - r % chnk - 1;

  straight = r < chnk;

  // 3 : 9
  // 4 : 7
  // query(4, 7)
  // xor_query(3, 3)
  // xor_query(8, 9)

  size_t result = 0;

  if (!straight && l2 < r2) {
    result += query(a, l2, r2 + 1);
    if (l2 > l) {
      result += xor_query(a, l, l2 - 1, k, true);
    }
    if (r2 < r) {
      result += xor_query(a, r2 + 1, r, k, true);
    }
    return result;
  }

  for (size_t i = l; i <= r; i++) {
    result += a[n + (i ^ k)];
  }

  return result;
}

void xor_assign(vector<ul> &a, size_t l, size_t r, size_t k, ul v,
                bool straight) {
  if (l == r) {
    assign(a, l ^ k, v);
    return;
  }

  size_t chnk = 2 << __lg(k);
  chnk = chnk == 0 ? 1 : chnk;

  bool inside_chunks = l % chnk == 0 && (r + 1) % chnk == 0;

  if (k == 0 || inside_chunks) {
    assign(a, l, r + 1, v);
    return;
  }

  // x : x >= l, x % chnk == 0
  size_t l2 = (l % chnk == 0) ? l : l + chnk - l % chnk;
  // x : x <= r, x % chnk == 0
  size_t r2 = ((r + 1) % chnk == 0) ? r : r - r % chnk - 1;

  straight = straight || r < chnk || l2 > r2;

  // 3 : 9
  // 4 : 7
  // query(4, 7)
  // xor_query(3, 3)
  // xor_query(8, 9)

  if (straight) {
    for (size_t i = l; i <= r; i++) {
      assign(a, i ^ k, v);
    }

    return;
  }

  assign(a, l2, r2 + 1, v);

  if (l2 > l) {
    xor_assign(a, l, l2 - 1, k, v, true);
  }
  if (r2 < r) {
    xor_assign(a, r2 + 1, r, k, v, true);
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
