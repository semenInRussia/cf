// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string al = "";
    unordered_set<char> h;
    for (auto ch : s) {
      if (!h.count(ch)) {
        h.insert(ch);
        al.push_back(ch);
      }
    }
    sort(al.begin(), al.end());

    map<char, char> m;
    int sz = (int)al.size();
    for (int i = 0; i < sz; i++) {
      m[al[i]] = al[sz - i - 1];
    }

    for (int i = 0; i < n; i++)
      s[i] = m[s[i]];

    cout << s << '\n';
  }
}
