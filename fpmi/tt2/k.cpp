// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int q = 0;

vector<int> ask(int x) {
  if (q == 16) {
    return {};
  }
  cout << "? " << (x + 1) << endl;
  q++;
  int k;
  cin >> k;
  if (k == 0) {
    exit(0);
  }
  vector<int> t(k);
  for (int i = 0; i < k; i++) {
    cin >> t[i];
    t[i]--;
  }
  return t;
}

bool used[1 << 8];

int ans = -1;

void dfs(int x, int fa = -1) {
  auto nxt = ask(x);
  used[x] = true;
  if (nxt.size() == 2ull) {
    ans = x;
    return;
  }
  for (int y : nxt) {
    if (y != fa) {
      dfs(y, x);
    }
  }
}

void solve() {
  int h;
  cin >> h;
  for (int i = 0; i < (1 << h); i++) {
    used[i] = false;
  }
  if (h == 0) {
    exit(0);
  }
  ans = -1;
  int x = rand() % ((1 << h) - 1);
  dfs(x, -1);
  if (ans != -1) {
    cout << "! " << (ans + 1) << "\n";
  } else {
    vector<int> buf;
    for (int i = 0; i < (1 << h); i++) {
      if (used[i]) {
        buf.push_back(i);
      }
    }
    cout << "! " << buf[rand() % buf.size()] + 1 << "\n";
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
