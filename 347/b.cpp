// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  unordered_set<string> h;
  h.rehash(1e6);

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n && i + k <= n; i++) {
      h.insert(s.substr(i, k));
    }
  }

  cout << h.size() << endl;
}
