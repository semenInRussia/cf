// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 1e6;
pair<int, int> f[N];

const int inf = 1e9 + 5;

pair<int, int> &setf(pair<int, int> &v, pair<int, int> op) {
  if (max(op.first, op.second) < max(v.first, v.second)) {
    v = op;
  }
  return v;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= 7 * n; i++) {
    f[i] = {+inf, +inf};
  }

  for (int i = 0; i < n; i++) {
    for (int d : {1, 2, 4}) {

      int a = i;
      int b = f[i].first;
      int c = f[i].second;

      // a+d, b, c

      int ar[3] = {a, b, c};

      for (int j = 0; j < 3; j++) {
        ar[j] += d;
        sort(ar, ar + 3);

        setf(f[ar[2]], {ar[1], ar[0]});

        ar[0] = a;
        ar[1] = b;
        ar[2] = c;
      }
    }
  }
}
