// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 500;
int st[N], en[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n), B(n);
  for (int i = 0; i < m; i++) {
    cin >> st[i] >> en[i];
    --st[i];
    --en[i];
    A[st[i]].push_back(i);
    B[en[i]].push_back(i);
  }

  for (int b = 0; b < (1 << m); b++) {
    vector<int> del(m);
    vector<pair<int, int>> ans; // {0, x} - add x to front
    deque<int> q;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      sort(B[i].begin(), B[i].end());

      while (!q.empty() && binary_search(B[i].begin(), B[i].end(), q.back())) {
        ans.push_back({2, q.back()});
        del[q.back()] = 1;
        q.pop_back();
      }

      while (!q.empty() && binary_search(B[i].begin(), B[i].end(), q.front())) {
        ans.push_back({2, q.front()});
        del[q.front()] = 1;
        q.pop_front();
      }

      for (int x : B[i]) {
        if (!del[x]) {
          ok = false;
        }
      }

      if (!ok) {
        break;
      }

      for (int x : A[i]) {
        if ((b >> x) & 1) {
          q.push_back(x);
          ans.push_back({1, x});
        } else {
          q.push_front(x);
          ans.push_back({0, x});
        }
      }
    }

    if (ok) {
      for (auto [t, x] : ans) {
        ++t;
        ++x;
        cout << t << " " << x << "\n";
      }
      exit(0);
    }
  }

  cout << "0\n";
}
