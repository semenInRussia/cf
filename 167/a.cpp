// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1000;
int x[maxn], y[maxn], ok[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  // (A. B) = (x[i], y[i] - h)
  // b = y[i] - h
  // h >= max(A, B)
  for (int i = 0; i < n; i++) {
    int a = x[i];
    const int lim = int(1e5);
    for (int b = -lim; b <= y[i] && !ok[i]; b++) {
      int h = max(abs(a), abs(b));
      if (b <= y[i] - h + 1)
        ok[i] = true;
    }
  }

  for (int i = 0; i < n; i++)
    cout << (ok[i] ? "YES\n" : "NO\n");
}
