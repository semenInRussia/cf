// Copyright 2024 semenInRussia

#include <fstream>
#include <vector>

using namespace std;

const int W = 10;

using ll = long long;

ll f[W][W], v[W][W + 1], h[W][W + 1], arr[W], lef[W + 2], righ[W + 2],
    top[W + 2], bot[W + 2];

ll maxsum() {
  ll bst = 0, cur = 0;
  for (int i = 0; i < W; i++) {
    cur = max(arr[i], cur + arr[i]);
    bst = max(bst, cur);
  }
  return bst;
}

int main() {
  ifstream cin("paintbarn.in");
  ofstream cout("paintbarn.out");

  int n, k;
  cin >> n >> k;

  // alg:
  // 1. do N queries:

  for (int z = 0; z < n; z++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    f[x1][y1]++, f[x2 + 1][y1]--;         // y1
    f[x1][y2 + 1]--, f[x2 + 1][y2 + 1]++; // y2+1
  }

  // 2. process them
  for (int x = 0; x < W; x++) {
    ll acc = 0;
    for (int y = 0; y < W; y++) {
      acc += f[x][y];
      f[x][y] = acc;
    }
  }

  for (int y = 0; y < W; y++) {
    ll acc = 0;
    for (int x = 0; x < W; x++) {
      acc += f[x][y];
      f[x][y] = acc;
    }
  }

  // orig=sum()
  ll orig = 0;
  for (int x = 0; x < W; x++)
    for (int y = 0; y < W; y++)
      orig += f[x][y] == k;

  // 3. replace (k-1 with 1) (k with -1) (x with 0)
  for (int x = 0; x < W; x++)
    for (int y = 0; y < W; y++)
      f[x][y] = (f[x][y] == k) ? -1 : ((f[x][y] == k - 1) ? +1 : 0);

  // - compute prefix sums
  // fill h[i][j] is is sum of f[i][0], f[i][1] ... f[i][j]
  for (int x = 0; x < W; x++) // column
    for (int y = 0; y < W; y++)
      h[x][y + 1] = h[x][y] + f[x][y]; // v[i] is prefix sum of column i

  for (int y = 0; y < W; y++)
    for (int x = 0; x < W; x++)
      v[y][x + 1] = v[y][x] + f[x][y]; // h[i] is prefix sum of row i

  // 4. for every x1, x2 find max sum

  for (int x1 = 0; x1 < W; x1++) {
    for (int x2 = x1 + 1; x2 <= W; x2++) {
      for (int y = 0; y < W; y++)
        arr[y] = h[y][x2] - h[y][x1];
      ll sum = maxsum();
      lef[x2 - 1] = max(lef[x2 - 1], sum);
      righ[x1] = max(righ[x1], sum);
    }
  }

  for (int y1 = 0; y1 < W; y1++) {
    for (int y2 = y1 + 1; y2 <= W; y2++) {
      for (int x = 0; x < W; x++)
        arr[x] = v[x][y2] - v[x][y1];
      ll sum = maxsum();
      bot[y1] = max(bot[y1], sum);
      top[y2 - 1] = max(top[y2 - 1], sum);
    }
  }

  // suffix sum for righ and bot
  for (int i = W - 1; i >= 0; i--) {
    righ[i] = max(righ[i + 1], righ[i]);
    bot[i] = max(bot[i + 1], bot[i]);
  }

  // // prefix sum for top and lef
  for (int i = 1; i < W; i++) {
    top[i] = max(top[i - 1], top[i]);
    lef[i] = max(lef[i - 1], lef[i]);
  }

  // write maxsum(arr)
  // 6. for every x setmax left[x-1], right[x]
  // 7. for every y setmax bot[y-1], top[y]
  ll dsum = 0; // the initially additional sum is zero, because we can do
               // nothing, that add +0
  for (int i = 1; i < W; i++) {
    dsum = max(dsum, lef[i - 1] + righ[i]);
    dsum = max(dsum, bot[i - 1] + top[i]);
  }

  cout << (dsum * 2);

  return 0;
}
