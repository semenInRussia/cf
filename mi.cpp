// Copyright 2024 semenInRussia

// take idea from USACO.

// idea that sometimes the answer is expected to be SO BIG, that ever in the
// condition authors tell us that we need to output a number with MOD.
// Here a small problem is that now after every +, -, += we need to
// also call % MOD, but we can automate this process using our own
// `struct` with some redefined operators

// this struct often called `mi`

using namespace std;
#include <iostream>

const int MOD = 1e9 + 7;

using ll = long long;
struct mi {
  ll v;
  mi(ll x = 0) : v(x % MOD) {} // initialize using integer
  explicit operator ll() { return v; }
};
mi operator+(mi a, mi b) { return mi(a.v + b.v); }
mi operator-(mi a, mi b) { return mi(a.v - b.v); }
mi operator*(mi a, mi b) { return mi(a.v * b.v); }
void operator+=(mi &a, int x) { a = a + mi(x); }

// showcase:
int main() {
  mi a = 0;
  for (int i = 0; i < 1'000'000'05; i++)
    a += i;
  cout << ll(a) << endl;
}
