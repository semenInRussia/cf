#include <cstdio>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int h = 0;
    while (a >= (1 << h))
      h++, a -= (1 << h);

    int e = (1 << h);
    e -= a;
    h++;
    if (b >= e)
      e = 0, b -= e;
    else
      e -= b, b = 0;
    if (e)
      c -= min(c, e);
    e = (1 << h) + a;
    int dif = 0;
    while (b) {
      dif = e - b;
      b -= min(b, e);
      h++;
    }
    int oldc = c;
    c -= min(dif, c);
    e -= min(e, oldc);
    while (c && e) {
      oldc = c;
      c -= min(c, e);
      e -= min(e, oldc);
      h++;
    }
    if (!e && c)
      h = -1;
    if (h > 0)
      h--;
    cout << h << '\n';
  }
}
