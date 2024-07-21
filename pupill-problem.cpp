// semenInRussia 2024
// https://codeforces.com/problemset/problem/1992/E
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int len(int x) {
  int d = 0;
  while (x) {
    x /= 10;
    d++;
  }
  return d;
}
using pii = pair<int, int>;
vector<pii> ans;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int d = len(n);
    string s = to_string(n);
    while ((int)s.size() < 10)
      s += s[s.size() % d];

    ans.clear();
    for (int a = 1; a <= 10000; a++) {
      for (int b = max(1, a * d - 10); abs(a * d - b) <= 10; b++) {
        // ad - b <= 8
        // b >= ad - 8
        int r = a * n - b;
        if (a * d - b != len(r) || b > min(a * n, 10000))
          continue;
        string t = to_string(a * n - b);
        if (equal(s.begin(), s.begin() + t.size(), t.begin()))
          ans.push_back({a, b});
      }
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans)
      cout << a << ' ' << b << '\n';
  }
}
