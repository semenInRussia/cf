using namespace std;

#include <iostream>
#include <vector>

int n, m, ai, aj, bi, bj;

bool in_one_step() {
  int d1 = 1, d2 = 2;
  for (auto s1 : {-1, 1})
    for (auto s2 : {-1, 1})
      if ((ai + d1 * s1 == bi && aj + d2 * s2 == bj) ||
          (ai + d2 * s1 == bi && aj + d1 * s2 == bj))
        return 1;
  return 0;
}

inline bool nocenter(int i, int j) { return i != 2 || j != 2; }

int main() {
  //
  cin >> n >> m >> ai >> aj >> bi >> bj;

  const bool b3 = n == 3 && m == 3;
  const bool supersmall = n < 2 && m < 2;

  bool ok = 1;
  ok &= !supersmall;
  ok &= (n > 2 && m > 2) || (in_one_step());
  ok &= !b3 || (nocenter(ai, aj) && nocenter(bi, bj));

  cout << (ok ? "YES\n" : "NO\n");
}
