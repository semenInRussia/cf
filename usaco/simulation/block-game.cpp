// Copyright 2024 semenInRussia

// a problem from usaco.guide
//
// https://usaco.org/index.php?page=viewproblem2&cpid=664&lang=ru

using namespace std;

#include <algorithm>
#include <fstream>
#include <vector>

int main() {
  ifstream cin("blocks.in");
  ofstream cout("blocks.out");

  int n;
  cin >> n;
  vector<pair<string, string>> a(n);

  for (auto &ai : a)
    cin >> ai.first >> ai.second;

  int ans[26];
  fill(ans, ans + 26, 0);
  for (char ch = 'a'; ch <= 'z'; ch++) {
    for (auto [w1, w2] : a) {
      ans[ch - 'a'] +=
          max(count(w1.begin(), w1.end(), ch), count(w2.begin(), w2.end(), ch));
    }
  }

  for (int i = 0; i < 26; i++)
    cout << ans[i] << '\n';
}
