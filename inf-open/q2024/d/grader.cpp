#include "table.h"
#include <iostream>

int main() {
  freopen("input.txt", "r", stdin);
  int n, t;
  std::cin >> n >> t;
  std::vector<int> r(t), c(t), v(t);
  for (int &x : r)
    std::cin >> x;
  for (int &x : c)
    std::cin >> x;
  for (int &x : v)
    std::cin >> x;
  int result = solve(n, t, r, c, v);
  std::cout << "=" << "\n";
  std::cout << result << "\n";

  return 0;
}
