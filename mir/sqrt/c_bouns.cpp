// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int N = 500;
int a[N], n;

bool check(int h) { // h - max amount of the groups
  // use either h or h-1
  for (int i = 0; i < n; i++) {
    int g = a[i] / h;
    // g-1 groups have size h, the last group is:
    int r = a[i] % h;
    if (r && r + g < h - 1)
      return false;
  }
  return true;
}

const int C = 200000; // 1e8 / 500;

int main() {
  cin >> n;
  int mn = -1;
  for (int i = 0; i < n; i++)
    cin >> a[i], mn = i ? min(a[i], mn) : a[i];

  int h = -1;
  for (int x = min(C, mn) + 2; x > 0; x--) {
    if (check(x)) {
      h = x;
      break;
    }
  }
  for (int k = 1; k <= C; k++) {
    int x = mn / k;
    for (int x : {x + 1, x}) {
      if (check(x)) {
        h = max(x, h);
        k = C + 1; // break outer for
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += (a[i] + h - 1) / h;
  cout << ans;
}
