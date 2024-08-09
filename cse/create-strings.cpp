// semenInRussia 2024
// https://cses.fi/problemset/task/1622
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
bool used[N];
vector<string> ans;
int n;
string s, cur;
void f(int i) {
  if (i == n) {
    ans.push_back(cur);
    return;
  }
  for (int j = 0; j < n; j++) {
    if (used[j])
      continue;
    used[j] = 1;
    cur.push_back(s[j]);
    f(i + 1);
    cur.pop_back();
    used[j] = 0;
  }
}

int main() {
  cin >> s;
  n = int(s.size());
  sort(s.begin(), s.end());
  f(0);
  sort(ans.begin(), ans.end());
  int u = unique(ans.begin(), ans.end()) - ans.begin();
  ans.resize(u);
  cout << ans.size() << '\n';
  for (auto w : ans)
    cout << w << '\n';
}
