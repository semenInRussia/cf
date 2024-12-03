#include <bitset>
using namespace std;

#include <iostream>
#include <vector>

using Seen = bitset<200>;

bool at(Seen &a, int i) {
  if (i < 0)
    return 1;
  return a[i];
}

int at(vector<int> &a, int i) {
  if (i < 0)
    return 0;
  return a[i];
}

template <typename T, typename U>
basic_ostream<T, U> &operator<<(basic_ostream<T, U> &out, vector<int> &a) {
  for (auto el : a)
    out << el << ' ';
  return out << "";
}

int a, b, n;
Seen seen = 0;

int solve(int beg) {
  vector<int> p(n + 1 + beg, 0);
  p[beg] = 1;
  for (int i = beg + 1; i <= n + beg; i++) {
    p[i] = at(p, i - a) * !at(seen, i - a) + //
           at(p, i - b) * !at(seen, i - b);
    p[i] *= !seen[i];
  }

  return p.back();
}

int main() {
  cin >> a >> b >> n;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    ans += solve(i);
    seen[i] = seen[i + n] = 1;
  }

  cout << ans << endl;

  return 0;
}
