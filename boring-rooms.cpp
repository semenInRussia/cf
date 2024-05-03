// Copyright 2023 semenInRussia

#include <iostream>

using namespace std;

size_t count_digs(size_t n);

int main() {
  size_t n, k;
  cin >> n >> k;

  size_t ndigs = count_digs(n - 1);
  size_t kdigs = count_digs(k);
  size_t dig = k % 10;

  cout << (ndigs * (dig - 1)) + kdigs << endl;

  return 0;
}

size_t count_digs(size_t n) {
  size_t len = 0;

  while (n) {
    n /= 10;
    len++;
  }

  return len;
}
