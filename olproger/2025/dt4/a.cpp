// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 100;
int a[N];

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') {
      r = i;
    }
  }
  int vh = -1;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') {
      if (a[i] > r) {
        vh = i;
      }
      break;
    }
  }

  r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      r = i;
    }
  }
  int vg = -1;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      if (a[i] > r) {
        vg = i;
      }
      break;
    }
  }

  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    if (i == vg && min(vg, vh) != -1) {
      ans++;
      continue;
    }
    if (s[i] == 'G') {
      ans += i <= vh && vh < a[i];
    } else {
      ans += i <= vg && vg < a[i];
    }
  }

  cout << ans;
}
