#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 6, W = 10;
int cur[W + 1], prv[W + 1];
int c[] = {5, 9, 3, 4, 100, 3}, w[] = {5, 1, 4, 1, 11, 1};
int n = sizeof(w) / sizeof(w[0]);

int main() {
  for (int i = 0; i < n; i++) {
    swap(prv, cur);
    for (int j = 0; j <= W; j++) {
      cur[j] = prv[j];
      if (w[i] <= j)
        cur[j] = max(cur[j], prv[j - w[i]] + c[i]);
    }
  }

  // answer is cur[W]
  cout << cur[W];
}
