// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

#pragma GCC optimize("O3")

int choose(vector<int> &s) {
  int sz = int(s.size());
  return s[rand() % sz];
}

const int N = 1005;
string t[N];

int n;

vector<int> solve() {
  vector<int> sp, s(n);
  for (int i = 0; i < n; i++) {
    s[i] = i;
  }
  vector<int> del(n);
  vector<int> ans;

  while (!s.empty()) {
    int x = choose(s);
    ans.push_back(x);
    del[x] = 1;
    for (int y : s) {
      if (t[x][y] == '0') {
        del[y] = 1;
      }
    }

    int j = 0;
    for (int i = 0; i < int(s.size()); i++) {
      int x = s[i];
      if (!del[x]) {
        s[j++] = x;
      }
      del[x] = 0;
    }
    s.resize(j);
  }

  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  vector<int> ans;

  int tt = 400;
  while (tt--) {
    vector<int> op = solve();
    if (op.size() > ans.size()) {
      swap(op, ans);
    }
  }

  cout << ans.size() << "\n";
  for (int x : ans) {
    cout << (x + 1) << " ";
  }
}
