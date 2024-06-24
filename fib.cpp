#include <iostream>
#include <map>
using namespace std;

map<int, int> lazy;

int fib(int a) {
  if (lazy.count(a))
    return lazy[a];
  // cout << a << '\n';
  if (a <= 1)
    return lazy[a] = 1;
  return lazy[a] = fib(a - 1) + fib(a - 2);
}

int main() {
  int n = 20;
  // cin >> n;
  cout << fib(n) << '\n';
}
