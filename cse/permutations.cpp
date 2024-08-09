// semenInRussia 2024
// https://cses.fi/problemset/task/1070
#include <iostream>
using namespace std;
int main() {
  // IDEA: all odd, all even
  // but if (max-even) - min(odd) == 1, ans = -1
  int n;
  cin >> n;
  int ev = n & ~1;
  if (ev == 2) {
    cout << "NO SOLUTION";
    return 0;
  }

  for (int i = 1; i * 2 <= n; i++)
    cout << i * 2 << ' ';
  for (int i = 0; i * 2 + 1 <= n; i++)
    cout << (i * 2 + 1) << ' ';
}
