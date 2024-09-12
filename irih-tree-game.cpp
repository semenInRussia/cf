// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int N = 2e5;
int out[N];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      out[i] = 0;
    }
    for (int j = 1; j < n; j++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      out[a]++, out[b]++;
    }
    string s;
    cin >> s;
    map<char, int> cnt;
    int w = 0; // count ? everywhere
    for (int i = 1; i < n; i++) {
      if (out[i] == 1) {
        cnt[s[i]]++;
      } else {
        w += s[i] == '?';
      }
    }

    int ans = -1;
    // maximize different
    if (s[0] == '?') {
      // observe, sometimes choose the root is an bad idea
      ans = max(cnt['0'], cnt['1']) + (cnt['?'] / 2);
      if (cnt['0'] == cnt['1']) {
        ans = cnt['0'] + ((cnt['?'] + (w & 1)) / 2);
      }
    } else {
      ans = cnt[('0' + '1') - s[0]] + (cnt['?'] + 1) / 2;
    }

    cout << ans << '\n';
  }
}
