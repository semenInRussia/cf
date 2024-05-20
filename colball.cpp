// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1954/D
// *1800
#include <iostream>
#include <numeric>
using namespace std;
const int mod = 998'244'353;

struct mi {
  int u;
  mi() : u(0) {}
  mi(int x) : u(x % mod) { u += (u < 0) * mod; }
};
mi operator+(mi a, mi b) { return mi(a.u + b.u); }
mi operator*(mi a, int b) { return mi(a.u * 1ll * b % mod); }
void operator+=(mi &a, mi b) { a = a + b; }

int a[5001];
mi d[5001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int s = accumulate(a, a + n, 0);
  d[0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = s - a[i]; j >= 0; j--)
      d[j + a[i]] += d[j];

  mi ans = 0;
  for (int j = 0; j <= s; j++)
    ans += d[j] * ((j + 1) / 2);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < a[i]; j++)
      ans += d[j] * ((a[i] - j) / 2);

  cout << ans.u << '\n';
}
