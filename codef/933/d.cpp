// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e6;
int a[N], b[N];
bool used[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  fill(used, used + n, 0);
  for (int i = 0; i < n; i++) {
    used[a[i] - 1] = 1;
  }

  vector<int> bad;
  for (int i = 1; i <= n; i++) {
    if (!used[i - 1]) {
      bad.push_back(i);
    }
  }

  fill(used, used + n, 0);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    if (used[x - 1]) {
      b[i] = bad.back();
      bad.pop_back();
    } else {
      b[i] = a[i];
    }
    used[x - 1] = 1;
  }

  // cout << "---\n";
  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }

  // cout << "\n";

  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }

  cout << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
