// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
  vector<ll> p = {1, 7, 8, 10, 3, 6,
                  7, 3, 2, 4,  5, 6}; // s[i] - max on [i+1; n)
  int n = (int)p.size();
  vector<ll> s(n + 1, 0);
  for (int i = n - 2; i >= 0; i--)
    s[i] = max(s[i + 1], p[i + 1]);

  for (int i = 0; i < n; i++)
    cout << s[i] << ' ';
  cout << '\n';
}
