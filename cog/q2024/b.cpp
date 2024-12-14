// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
using namespace std;

void solve() {
  int n;
  cin >> n;

  map<int, string> mp;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int id;
    char prob, verd, _trash;

    sscanf(s.data(), "cognitive-2025-%d,%c,%c%c\n", &id, &prob, &verd, &_trash);

    if (verd == 'O') {
      mp[id].push_back(prob);
    }
    if (!mp.count(id)) {
      mp[id] = "";
    }
  }

  pair<int, int> A = {0, 0};

  for (auto &[id, h] : mp) {
    sort(h.begin(), h.end());
    int u = unique(h.begin(), h.end()) - h.begin();
    pair<int, int> op = {u, 1};
    if (op.first == A.first) {
      A.second += op.second;
    } else {
      A = max(op, A);
    }
  }

  cout << A.second << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
