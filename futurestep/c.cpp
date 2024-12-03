// semenInRussia 2024
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 9 * 60 = 540

const int N = 540;
bool bad[N], take[N];

const int W = 30, F = 20;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, s;
    int b, t;
    scanf("%d:%d-%d:%d", &a, &s, &b, &t);
    int l = (a - 9) * 60 + s;
    int r = (b - 9) * 60 + t;
    for (int i = l; i < r; i++) {
      bad[i] = 1;
    }
    assert(r <= N);
  }
  int ans = 0;
  int t = 0;
  bool working = 1;
  for (int i = 0; i < N; i++) {
    if (bad[i]) {
      if (working) {
        // cout << "Stop at " << ((i / 60) + 9) << ":" << (i % 60) << '\n';
        working = t = 0;
      }
      t++;
    } else {
      if (working) {
        if (t >= W) {
          working = 0;
          t = 1;
          // cout << "Stop at " << ((i / 60) + 9) << ":" << (i % 60) << '\n';
        } else {
          t++;
          ans++;
        }
      } else {
        if (t >= F) {
          working = 1;
          t = 1;
          ans++;
          // cout << "Start at " << ((i / 60) + 9) << ":" << (i % 60) << '\n';
        } else {
          t++;
        }
      }
    }
  }
  cout << ans;
}
