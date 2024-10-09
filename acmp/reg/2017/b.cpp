// semenInRussia 2024
// https://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=181&id_problem=1187
#include <iostream>
using namespace std;
using ll = long long;

const int N = 61;
ll f[N][N][N];

int main() {
  // A (x/2)
  // B (x+1)/2
  // C (x-1)/2
  ll n;
  int a, b, c;
  cin >> n >> a >> b >> c;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        if ((i + j + k) == 0) {
          f[i][j][k] = n;
          continue;
        }
        ll &ans = f[i][j][k];
        ans = n + 1;
        if (i) {
          ans = min(ans, f[i - 1][j][k] / 2);
        }
        if (j) {
          ans = min(ans, (f[i][j - 1][k] + 1) / 2);
        }
        if (k) {
          ans = min(ans, (f[i][j][k - 1] - 1) / 2);
        }
      }
    }
  }
  cout << f[a][b][c];
}
