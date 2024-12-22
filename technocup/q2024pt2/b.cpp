// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int M = 27;
const int N = 1e4 + 100;

int a[N][M];
vector<int> sols[M];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string c;
      cin >> c;
      a[i][j] = c == "+";
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        sols[j].push_back(i);
      }
    }
  }

  for (int j = 0; j < m; j++) {
    sort(sols[j].begin(), sols[j].end());
  }

  bool ans = 1;

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (sols[i] == sols[j]) {
        ans = 0;
      }
    }
  }

  cout << ans;
}
