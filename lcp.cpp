// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1968/G1
#include <iostream>

using namespace std;

int n, l, r;
string str;
const int maxn = 2e5 + 10;
int pi[2 * maxn];

bool check(int k) {
  string s = str.substr(0, k);
  s += "|", s += str;
  int m = (int)s.size();

  // pi function
  pi[0] = 0;
  for (int i = 1; i < m; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[j] != s[i])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }

  // count string occurrences
  int cnt = 0;
  for (int i = k + 1; i < m; i++)
    if (pi[i] == k)
      cnt++, i += k - 1;

  return cnt >= l;
}

void solve() {
  cin >> n >> l >> r >> str;
  int high = n + 1;
  int low = 0;
  while (high > low + 1) {
    int mid = (high - low) / 2 + low;
    if (check(mid))
      low = mid;
    else
      high = mid;
  }

  cout << low << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
