// semenInRussia 2024
#include <iostream>
using namespace std;

struct jury {
  int t1, t2, t3, t4, t5;

  int bus() {
    if (t1 < t2) { // bus not start movement
      return t2;
    }
    // bus start
    auto k = (t1 - t2 + t3 - 1) / t3;
    return t2 + k * t3;
  }
};

void readtime(int &x) {
  int h, m;
  scanf("%d:%d", &h, &m);
  x = h * 60 + m;
}

istream &operator>>(istream &in, jury &v) {
  readtime(v.t1);
  readtime(v.t2);
  readtime(v.t3);
  readtime(v.t4);
  readtime(v.t5);
  return in;
}

void outtime(int t) {
  int h = t / 60;
  h %= 24;
  int m = t % 60;
  printf("%02d:%02d\n", h, m);
}

void solve() {
  jury a, b, c;
  cin >> a >> b >> c;
  int e = 0;
  for (auto v : {a, b, c}) {
    e = max(e, v.bus() + v.t4 + v.t5);
  }
  outtime(e);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
