// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 500;
int p[N], k[N], s[N];

int main() {
  int n, K;
  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }

  int ans = 0;

  for (int b = 0; b < (1 << n); b++) {
    vector<int> usd(n);
    int kk = 0;
    int ss = 0;
    for (int j = 0; j < n; j++) {
      if ((b >> j) & 1) {
        // add j
        int x = j;
        while (x != -1 && !usd[x]) {
          // cerr << "." << endl;
          kk += k[x];
          ss += s[x];
          usd[x] = true;
          x = p[x];
        }
      }
    }
    if (kk <= K) {
      if (ss == 65) {
        for (int i = 0; i < n; i++) {
          if (usd[i]) {
            cout << (i + 1) << " ";
          }
        }
        cout << "\n";
      }
      ans = max(ss, ans);
    }
  }

  cout << ans;
}
