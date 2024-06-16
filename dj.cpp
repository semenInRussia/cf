#include <iostream>
int n, t, c, a, x, i;
std::string s;
void solve() {
  std::cin >> n >> s;
  a = n;
  for (x = n; x > 1;) {
    x--;
    if (n % x)
      continue;
    for (int o : {0, x}) {
      c = 0;
      for (i = 0; i < n; i++)
        c += s[i] != s[i % x + o];
      if (c < 2)
        a = x;
    }
  }
  std::cout << a << '\n';
}
int main() {
  std::cin >> t;
  while (t--)
    solve();
}
