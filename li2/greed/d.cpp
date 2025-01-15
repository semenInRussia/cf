// semenInRussia 2025
using namespace std;
#include <bits/stdc++.h>

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s, t;
  cin >> s >> t;
  sort(t.begin(), t.end());
  int j = (int)t.size() - 1;

  for (char &c : s)
    if (j >= 0 && t[j] > c)
      c = t[j--];

  cout << s;
}
