// Copyright 2024 semenInRussia

#include <bits/stdc++.h>
using namespace std;

using numb = __int128;
const numb inf = LLONG_MAX;

const int maxn = 6e4;
numb x[maxn], v[maxn];
int n;

const numb NS = 1e9; // nanoseconds in one second

bool check(numb time) { // time in nanoseconds!!
  numb l = 0, r = inf;  // where can be located the point
  for (int i = 0; i < n; i++) {
    numb mn = x[i] - v[i] * time;
    numb mx = x[i] + v[i] * time;
    if (r < mn || l > mx)
      return false;
    l = max(l, mn), r = min(r, mx);
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    x[i] = NS * (numb)a;
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = (numb)a;
  }

  numb l = 0, r = inf;
  while (r > l + 1) {
    numb m = (r - l) / 2 + l;
    if (check(m))
      r = m;
    else
      l = m;
  }

  printf("%d.%09d", int(r / NS), int(r % NS));
}
