// semenInRussia 2024
#include <ios>
#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const int maxn = 100;
ll k[maxn];
ll M = 1;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> k[i];

  ll sm = 0;
  for (int i = 0; i < n; i++)
    sm += M / k[i];
  if (sm < M) {
    for (int i = 0; i < n; i++)
      cout << (M / k[i]) << ' ';
    cout << "\n";
    return;
  }
  cout << "-1\n";
}

int main() {
  int tt;
  cin >> tt;
  for (int i = 2; i <= 20; i++)
    M = lcm(M, i);
  while (tt--)
    solve();
}
