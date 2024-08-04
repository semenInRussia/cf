// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;

const int M = 2e6, mod = 1e9 + 7, C = 123;
int h[M], ht[M], p[M];
void concat(string &s, string &t) {
  // sample please
  int n1 = int(s.size()), n2 = int(t.size());

  // count hash for t (string 2)
  for (int i = 0; i < n2; i++)
    ht[i + 1] = (1ll * t[i] * p[i] + ht[i]) % mod;
  int nn = max(n1, n2);
  int pi = 0; // length common suffix/prefix
  for (int i = min(n1, n2); i > 0; i--) {
    // aa is suffix of s
    int aa = (h[n1] - h[n1 - i]) % mod;
    if (aa < 0)
      aa += mod;
    aa = 1ll * aa * p[nn - (n1 - i)] % mod;

    // bb is prefix of t
    int bb = 1ll * ht[i] * p[nn] % mod;

    // check them
    if (aa == bb) {
      pi = i;
      break;
    }
  }

  for (int i = 0; i < pi; i++)
    s.pop_back();
  s += t;

  int n = int(s.size());
  for (int i = n1 - pi; i < n; i++)
    h[i + 1] = (1ll * s[i] * p[i] + h[i]) % mod;
}

int main() {
  int n;
  string s, t;
  cin >> n >> s;
  p[0] = 1;
  for (int i = 0; i + 1 < M; i++)
    p[i + 1] = (1ll * p[i] * C) % mod;
  for (int i = 0; i < int(s.size()); i++)
    h[i + 1] = (1ll * s[i] * p[i] + h[i]) % mod;
  for (int i = 1; i < n; i++) {
    cin >> t;
    concat(s, t);
  }

  cout << s;
}
