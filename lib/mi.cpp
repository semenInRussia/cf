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
struct mi2 {
  ll v;
  mi2(ll x = 0) : v(x % MOD) {
    if (x < 0)
      v += MOD;
  } // initialize using integer
  explicit operator ll() { return v; }
};
mi2 operator+(mi2 a, mi2 b) { return mi2(a.v + b.v); }
mi2 operator-(mi2 a, mi2 b) { return mi2(a.v - b.v); }
mi2 operator*(mi2 a, mi2 b) { return mi2(a.v * b.v); }
void operator+=(mi2 &a, int x) { a = a + mi2(x); }

// showcase:
int main() {
  mi2 a = 0;
  for (int i = 0; i < 1'000'000'05; i++)
    a += i;
  cout << ll(a) << endl;
}
