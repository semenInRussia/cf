// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define q(i) (data.query(i))

inline size_t is_between(size_t x, size_t l, size_t r) {
  return x <= max(l, r) && x >= max(l, r);
}

inline size_t prv(size_t i, size_t n) { return i ? i - 1 : n - 1; }
inline size_t nxt(size_t i, size_t n) { return (1 + i) % n; }

class Secret {

public:
  vector<size_t> a;
  set<size_t> seen;
  set<size_t> checked;

  Secret(size_t n) {
    vector<size_t> a(n);
    this->a = a;
  }

  Secret(vector<size_t> a) { this->a = a; }

  bool is_break(size_t i) noexcept {
    const size_t n = a.size();
    const size_t x = query(i);
    const size_t prev = query(prv(i, n));
    const size_t next = query(nxt(i, n));

    return (x > prev) != (next > x);
  }

  bool is_checked(size_t i) noexcept { return checked.count(i) > 0; }
  bool is_found(size_t x) noexcept { return seen.count(x) > 0; }

  size_t query(size_t i) {
    if (is_checked(i))
      return a[i];

    cin.clear();
    cout << i + 1 << endl;
    cin >> a[i];

    checked.insert(i);
    seen.insert(a[i]);

    return a[i];
  }

  bool find_elem(size_t x, size_t l, size_t r) {
    const bool dir = query(r) > query(l);

    if (is_found(x)) {
      return true;
    }

    if (!is_between(x, query(l), query(r))) {
      return false;
    }

    while (l <= r) {
      size_t mid = (l + r) / 2;
      size_t num = query(mid);
      if (num == x)
        return true;

      if ((dir && num > x) || (!dir && (num < x))) {
        // left
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return false;
  }
};

size_t find_break(Secret &data, size_t beg = 0, size_t end = 0,
                  bool dir = true) {
  size_t n = data.a.size();

  size_t l = beg;
  size_t r = end ? end : n - 1;

  while (l <= r) {
    const size_t i = (l + r) / 2;

    const size_t x = q(i);
    const size_t prev = q(prv(i, n));
    const size_t next = q(nxt(i, n));

    if ((x > prev) != (next > x))
      return i;

    if ((x > prev && dir) || (x < prev && !dir)) {
      // right
      l = i + 1;
      if (l == n)
        return n - 1;
    } else {
      // left
      if (!i)
        return 0;
      r = i - 1;
    }
  }

  return 0;
}

int main() {
  size_t n, k;
  cin >> n >> k;

  vector<size_t> elems(k);

  for (auto &el : elems) {
    cin >> el;
  }

  return 0;
};
