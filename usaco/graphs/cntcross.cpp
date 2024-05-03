// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int maxn = 100;
bool used[maxn][maxn], road[maxn][maxn], cow[maxn][maxn];
int comp[maxn][maxn], cnt[maxn]; // cnt - counter of component occurences
vector<vector<int>> g;

int k, n, r;

void dfs(int i, int j, int num) {
  if (i < 0 || i >= n || j < 0 || j >= n || used[i][j] || road[i][j])
    return;
  used[i][j] = true;
  comp[i][j] = num;
  for (int d : {-1, +1})
    dfs(i + d, j, num), dfs(i, j + d, num);
}

int main() {
  ifstream cin("countcross.in");
  ofstream cout("countcross.out");

  cin >> n >> k >> r;

  for (int z = 0; z < r; z++) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--, j1--, i2--, j2--;
    if (i1 > i2)
      swap(i1, i2);
    if (j1 > j2)
      swap(j1, j2);
    for (int i = i1; i <= i2; i++)
      for (int j = j1; j <= j2; j++)
        road[i][j] = 1;
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++)
  //     cout << (road[i][j] ? "#" : ".");
  //   cout << "\n";
  // }

  int num = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!used[i][j])
        dfs(i, j, num++);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (road[i][j])
        comp[i][j] = num++;

  vector<pii> cows;
  for (int z = 0; z < k; z++) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    cows.push_back({i, j});
  }

  ll ans = 0, m = (int)cows.size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (comp[cows[i].first][cows[i].second] !=
              comp[cows[j].first][cows[j].second] &&
          (abs(cows[i].first - cows[j].first) +
               abs(cows[i].second - cows[j].second) ==
           1)) {
        ans++;
      }
    }
  }

  cout << (ans / 2) << endl;
}
