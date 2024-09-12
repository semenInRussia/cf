// https://codeforces.com/contest/2003/problem/C
// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto ch : s) {
      cnt[ch]++;
    }
    string ans = "";
    while (!cnt.empty()) {
      vector<char> kill;
      for (auto &[ch, v] : cnt) {
        ans += ch;
        v--;
        if (v == 0) {
          kill.push_back(ch);
        }
      }
      for (int x : kill) {
        cnt.erase(x);
      }
    }
    cout << ans << '\n';
  }
}
