// Copyright 2023 semenInRussia

#define TEST

#include <cstdio>
#include <fstream>
#include <vector>

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define min2(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

using ul = unsigned long long;

enum ChunksType {
  No,
  OnBounds,
  Inside,
};

struct Chunks {
  ChunksType typ;
  size_t l;
  size_t r;
};

Chunks inside_chunks(size_t k, size_t l, size_t r);

enum Direction {
  Up,
  Down,
};

struct Curve {
  Direction dir;
  size_t chunk;
  size_t big_chunk;
  size_t k;
};

Curve inspect(size_t k);
ul curve_max(Curve curve);

ul query(vector<ul> &b, size_t l, size_t r);
ul xor_query(vector<ul> &b, size_t l, size_t r, size_t k);

void update(vector<ul> &a, vector<ul> &b, size_t l, size_t r, ul x);
void xor_update(vector<ul> &a, vector<ul> &b, size_t l, size_t r, size_t k,
                ul x);

void xor_update(vector<ul> &a, vector<ul> &b, size_t l, size_t r, size_t k,
                ul x) {
  for (size_t i = l; i <= r; i++) {
    update(a, b, i ^ k, (i ^ k) + 1, x);
  }
}

#ifdef TEST

#include <iostream>

int main() {
  size_t n = 8;
  vector<ul> a{1, 2, 3, 4, 5, 6, 7, 8};
  vector<ul> b(n + 1);

  for (size_t i = 0; i < n; i++) {
    b[i + 1] = b[i] + a[i];
  }

  for (size_t l = 0; l < n; l++) {
    for (size_t r = l; r < n; r++) {
      for (size_t k = 0; k < n; k++) {
        cout << l << ", " << r << ", " << k << endl;

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
          expected += a[i ^ k];
        }

        ul actual = xor_query(b, l, r, k);

        if (expected != actual) {
          cout << endl
               << "---" << endl
               << "l, r, k = " << l << ", " << r << ", " << k << endl;
          actual = xor_query(b, l, r, k);

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
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  size_t d;
  fin >> d;

  size_t n = 1 << d;
  vector<ul> a(n);

  for (size_t i = 0; i < n; i++) {
    fin >> a[i];
  }

  vector<ul> b(n + 1);

  for (size_t i = 0; i < n; i++) {
    b[i + 1] = b[i] + a[i];
  }

  size_t q;
  fin >> q;

  for (size_t i = 0; i < q; i++) {
    size_t typ, l, r, k;
    fin >> typ >> l >> r >> k;

    if (typ == 2) {
      // cout << xor_query(b, l, r, k) << endl;
      fout << xor_query(b, l, r, k) << endl;
    } else {
      size_t x;
      fin >> x;
      xor_update(a, b, l, r, k, x);
    }
  }

  return 0;
}

#endif

ul query(vector<ul> &b, size_t l, size_t r) {
  // 1 2 3
  // 0 1 3 6
  // ---
  // 1,3 -> 0 - 0+1+2
  return b[r] - b[l];
}

void update(vector<ul> &a, vector<ul> &b, size_t l, size_t r, ul x) {
  for (size_t i = l; i < r; i++) {
    a[i] = x;
  }

  for (size_t i = l; i < a.size(); i++) {
    b[i + 1] = b[i] + a[i];
  }
}

Curve inspect(size_t k) {
  if (k == 0) {
    return {Down, 1};
  }

  bool dir = k < (k ^ 1);
  size_t i = 2;

  while (dir == ((k ^ i) > (k ^ (i - 1)))) {
    i *= 2;
  }

  Curve c;

  c.dir = dir ? Up : Down;
  c.chunk = i;
  c.big_chunk = 2 << __lg(k);
  c.k = k;

  return c;
}

ul xor_query(vector<ul> &b, size_t l, size_t r, Curve curve) {
  size_t k = curve.k;

  if (k == 0) {
    return query(b, l, r + 1);
  }

  if (k > l && k < r) {
    return xor_query(b, l, k, curve) + xor_query(b, k + 1, r, curve);
  }

  return 0;
}

inline ul xor_query(vector<ul> &b, size_t l, size_t r, size_t k) {
  return xor_query(b, l, r, inspect(k));
}

Chunks inside_chunks(size_t k, size_t l, size_t r) {
  if ((r + 1) % k == 0 && l % k == 0) {
    return {OnBounds, l, r};
  }

  size_t l2 = (l == 0) ? 0 : l + k - l % k;
  size_t r2 = r - r % k - 1;

  if (r2 >= l && l2 <= r && l2 <= r2) {
    return {Inside, l2, r2};
  }

  return {No};
}
