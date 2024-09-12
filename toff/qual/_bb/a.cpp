// semenInRussia 2024
// https://ejudge.algocourses.ru/cgi-bin/new-client?SID=09e6bb8aae26a762&action=139&prob_id=13
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("unroll-loops,Ofast")

int mp[10] = {
    6, // 0
    2, // 1
    5, // 2
    5, // 3
    4, // 4
    5, // 5
    6, // 6
    3, // 7
    7, // 8
    6, // 6
};

vector<int> c;
int n, k;

const int N = 2e5;

bool used[N];
pair<int, int> memo[N];
// {size, nxt}, size = -1 if bad
pair<int, int> f(int rst, bool fst = 0) {
  if (rst == 0) {
    return {0, 0};
  }
  if (rst < 0) {
    return {-1, 0};
  }
  if (used[rst]) {
    return memo[rst];
  }
  used[rst] = 1;
  pair<int, int> &ans = memo[rst];
  ans = {-1, 0};
  for (int j = k - 1; j >= 0; j--) {
    if (fst && c[j] == 0) {
      continue;
    }
    auto cur = f(rst - mp[c[j]]);
    if (cur.first >= 0) {
      cur.second = c[j];
      cur.first++;
    }

    ans = max(ans, cur);
  }

  return memo[rst] = ans;
}

int main() {
  cin >> n >> k;
  c.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());
  pair<int, int> cur = f(n, 1);
  int r = n;
  while (r > 0) {
    int dig = cur.second;
    cout << dig;
    r -= mp[dig];
    cur = f(r);
  }
}
