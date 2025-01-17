
// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;

bool g(int64_t i);

bool f(int64_t i) {
  if (i <= 2) {
    return i & 1;
  }

  auto j = (i - 1) / 2;
  auto ans = i & 1;

  if (j & 1) {
    ans ^= g(j);
  } else {
    ans ^= (j / 2) & 1;
  }

  return ans;
}

bool g(int64_t i) {
  if (i <= 1) {
    return i;
  }

  auto j = i / 2;
  auto ans = (j + 1) & 1;

  if (j & 1) {
    ans ^= g(j);
  } else {
    ans ^= (j / 2) & 1;
  }

  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n;
    cin >> n;
    bool ok = 1;

    if (n & 1) {
      ok ^= f(n / 2);
    }

    cout << (ok ? "Alice\n" : "Bob\n");
  }
}
