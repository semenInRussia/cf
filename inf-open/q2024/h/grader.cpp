#include "tree.cpp"
#include <iostream>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::vector<int> qt(q), qx(q), qy(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> qt[i] >> qx[i] >> qy[i];
  }
  auto result = solve(n, q, a, p, qt, qx, qy);
  for (int x : result) {
    std::cout << x << "\n";
  }
  return 0;
}
