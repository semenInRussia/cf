// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int c, h1, h2, w1, w2;
  cin >> c >> h1 >> h2 >> w1 >> w2;

  if (w1 > w2) {
    swap(w1, w2);
    swap(h1, h2);
  }
  const int A = c / w2;
  const int G = 1.5e7;

  // 0, min(G, A)
  // max(0, A-G), A
  ll ans = 0;
  int l = 0, r = min(G, A);
  for (int z : {1, 2}) {
    for (int a = l; a <= r; a++) {
      if (1ll * a * w2 > ll(c))
        break;
      int b = (c - (a * w2)) / w1;
      ans = max(ans, 1ll * a * h2 + 1ll * b * h1);
    }
    l = max(0, A - G), r = A;
  }

  cout << ans;
}
