// semenInRussia 2025
#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
#pragma GCC target("avx2")

using namespace std;

uint64_t cube(int x) { return 1ull * x * x * x; }

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    sort(words.begin(), words.end());

    auto id = [&](string w) -> int {
      auto it = lower_bound(words.begin(), words.end(), w);
      if (it == words.end() || *it != w) {
        return 0;
      }
      return it - words.begin() + 1;
    };

    int n = (int)s.size();
    int len = (int)words[0].size();
    int m = (int)words.size() * len;

    uint64_t exp = 0;
    for (auto w : words) {
      exp += cube(id(w));
    }

    vector<int> ans;
    ans.reserve(n);

    for (int t = 0; t < len; t++) { // t - is offset
      vector<uint64_t> val(n), pref(n + 1);
      for (int i = t; i + len <= n; i += len) {
        val[i] = cube(id(s.substr(i, len)));
      }
      for (int i = 0; i < n; i++) {
        pref[i + 1] = val[i] + pref[i];
      }

      for (int i = t; i + m <= n; i += len) {
        if (pref[i + m] - pref[i] == exp) {
          ans.push_back(i);
        }
      }
    }

    return ans;
  }
};

#ifdef home
int main() {
  string s = "barfoofoobarthefoobarman";
  vector<string> words = {"bar", "foo", "the"};
  Solution sol;
  auto ans = sol.findSubstring(s, words);
  cerr << "{";
  for (int j : ans) {
    cerr << j << " ";
  }
  cerr << "}";
}
#endif
