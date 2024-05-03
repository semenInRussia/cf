// Copyright 2024 semenInRussia

#include <iostream>
#include <set>
#include <vector>

using namespace std;

string s;
int n;
vector<int> stars, packs; // indexes of stars and packmans

bool check(int t) {
  int m = (int)stars.size();
  int ptr = 0;

  for (int x0 : packs) {
    if (ptr == m)
      break;
    int r = max(x0, stars[ptr]);
    int l = min(x0, stars[ptr]);
    for (; ptr < m && (r - l + min(r - x0, x0 - l)) <= t; ptr++) {
      r = max(r, stars[ptr + 1]);
      l = min(l, stars[ptr + 1]);
    }
  }

  return ptr == m;
}

int main() {
  cin >> n >> s;

  for (int i = 0; i < n; i++)
    if (s[i] == '*')
      stars.push_back(i);
    else if (s[i] == 'P')
      packs.push_back(i);

  int l = 0, r = 2 * n + 2;
  while (r > l + 1) {
    int mid = (r + l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }

  cout << r << endl;
}
