// semenInRussia 2024
// Merge sort tree fenwick
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> t[N];

int n;

void add(int l, int x) { // add x to [0; l)
  for (; l <= n; l += l & -l) {
    t[l].push_back(x);
  }
}

int count(int i, int a, int b) {
  // count elements (a <= x <= b) on interval [0; i)
  int ans = 0;
  for (; i > 0; i -= i & -i) {
    // ans += range
    ans += upper_bound(t[i].begin(), t[i].end(), b) -
           lower_bound(t[i].begin(), t[i].end(), a);
  }
  return ans;
}

int count(int x, int y, int k, int l) {
  return count(y, k, l) - count(x, k, l);
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(i, x);
  }

  for (int j = 0; j <= n; j++) {
    sort(t[j].begin(), t[j].end());
  }

  for (int i = 0; i < m; i++) {
    int x, y, k, l;
    cin >> x >> y >> k >> l;
    cout << count(x - 1, y, k, l) << "\n";
  }
}
