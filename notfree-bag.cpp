// Copyright 2024 semenInRussia
#include <algorithm>
using namespace std;

const int maxn = 6, W = 10;
int d[maxn][W + 1];
int c[] = {5, 9, 3, 1}, w[] = {5, 5, 4, 3};
int n = sizeof(w) / sizeof(w[0]);
int main() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= W; j++) {
      d[i + 1][j] = d[i][j];
      if (w[i] <= j)
        d[i + 1][j] = max(d[i + 1][j], d[i][j - w[i]] + c[i]);
    }
  }
}
