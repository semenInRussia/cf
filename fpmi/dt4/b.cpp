// semenInRussia 2025
#pragma GCC optimize("Ofast,unroll-loops")
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <math.h>
#include <vector>
#ifndef home
#pragma GCC target("avx2")
#endif
#include <cassert>

using namespace std;

const int N = 5005;
int a[N];
int l, n;

int mn = n;
int mx = -1;

const int inf = 2e9 + 100;

pair<int, string> build(vector<pair<int, int>> &buf) {
  string s = "[";
  int score = 0;
  for (auto [a, b] : buf) {
    score += b - a + 1;
    if (a == b) {
      s += to_string(a);
      s += ',';
    } else {
      s += to_string(a);
      s += "..";
      s += to_string(b);
      s += ',';
    }
  }
  if (s.back() == ',') {
    s.pop_back();
  }
  s += ']';
  return {score, s};
}

vector<pair<int, int>> gen(bitset<N> &b) {
  vector<pair<int, int>> buf;
  for (int j = 0; j < n; j++) {
    int mode = b[j];
    if (mode == 0) { // take by one
      buf.push_back({a[j], a[j]});
    } else { // take by range
      if (buf.empty()) {
        buf.push_back({a[j], a[j]});
      }
      buf.back().second = a[j];
    }
  }
  return buf;
}

int f(bitset<N> b) {
  vector<pair<int, int>> buf = gen(b);
  // count score, build s
  auto [score, s] = build(buf);
  if ((int)s.size() <= l) {
    return score;
  }
  return +inf;
}

int dp[N][N];
pair<int, int> prv[N][N];

int len(int x) {
  int l = 0;
  while (x) {
    x /= 10;
    l++;
  }
  return l;
}

void solve3() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= l; j++) {
      dp[i][j] = +inf;
      prv[i][j] = {-1, -1};
    }
  }
  dp[0][len(a[0]) + 2] = 1;

  for (int i = 1; i < n; i++) { // amount of used bridges
    int l1 = len(a[i]);
    for (int j = 0; j <= l; j++) { // length of string
      if (j - l1 - 1 >= 0) {
        int op = dp[i - 1][j - l1 - 1] + 1;
        if (op < dp[i][j]) {
          dp[i][j] = op;
          // cerr << "(" << i - 1 << ", " << j - l1 - 1 << ") => " << "(" << i
          //      << ", " << j << ")\n";
          prv[i][j] = {i - 1, j - l1 - 1};
        }
      }

      if (j - l1 - 3 >= 0) {
        for (int k = 0; k < i; k++) {
          if (dp[k][j - l1 - 3] >= inf) {
            continue;
          }
          int op = dp[k][j - l1 - 3] + a[i] - a[k];
          if (op < dp[i][j]) {
            // cerr << "(" << k << ", " << j - l1 - 3 << ") => " << "(" << i
            //      << ", " << j << ")\n";
            dp[i][j] = op;
            prv[i][j] = {k, j - l1 - 3};
          }
        }
      }

      if (dp[i][j] < inf) {
        cout << "(" << i << ", " << j << ") == " << dp[i][j] << "\n";
      }
    }
  }

  int i = n - 1;
  int j = l - 1;
  vector<int> nums;
  while (i != -1) {
    auto [i2, j2] = prv[i][j];
    nums.push_back(i);
    j = j2;
    i = i2;
  }

  // cerr << "nums: \n";
  // for (int x : nums) {
  //   cerr << x << "\n";
  // }

  reverse(nums.begin(), nums.end());

  string s = "[" + to_string(a[0]) + ',';
  for (int k = 1; k < (int)nums.size(); k++) {
    if (nums[k] != nums[k - 1] + 1) {
      s.pop_back(); // ,
      s += "..";
      s += to_string(a[nums[k]]);
      s += ',';
    } else {
      s += to_string(a[nums[k]]);
      s += ',';
    }
  }
  if (s.back() == ',') {
    s.pop_back();
  }
  s += ']';
  cout << s;
  assert((int)s.size() <= l);
}

void solve20() {
  int bst = mx - mn + 1;
  string ans = "[" + to_string(mn) + ".." + to_string(mx) + "]";

  for (int b = 0; b < (1 << n); b++) {
    vector<pair<int, int>> buf;

    for (int j = 0; j < n; j++) {
      int mode = (b >> j) & 1;
      if (mode == 0) { // take by one
        buf.push_back({a[j], a[j]});
      } else { // take by range
        if (buf.empty()) {
          buf.push_back({a[j], a[j]});
        }
        buf.back().second = a[j];
      }
    }

    // count score, build s
    string s = "[";
    int score = 0;
    for (auto [a, b] : buf) {
      score += b - a + 1;
      s += to_string(a);
      if (b != a) {
        s += "..";
        s += to_string(b);
      }
      s += ',';
    }
    if (s.back() == ',') {
      s.pop_back();
    }
    s += ']';

    // maybe update
    if (score < bst && (int)s.size() <= l) {
      ans = s;
      bst = score;
    }
  }

  cout << ans << "\n";
}

double rnd() { return double(rand()) / RAND_MAX; }
bool go(double T, int val, int ans) {
  return rnd() < exp((ans - val) / T);
  // return false;
}

int main() {
  cin >> l >> n;

  mn = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }

  sort(a, a + n);

  if (n <= 100) {
    solve3();
    return 0;
  }

  bitset<N> b;

  for (int i = 0; i < n; i++) {
    b[i] = 1;
  }

  int ans = f(b);
  bitset<N> bst = b;
  double T = 1;
  int MAX_IT = n > 200 ? 7000 : 200000;

  for (int i = 0; i < MAX_IT; i++) {
    T *= 0.999;
    auto u = b;
    int x = rand() % n;
    u[x] = u[x] ^ 1;
    int val = f(u);
    if (val < ans) {
      bst = u;
    }
    if (val < ans || go(T, val, ans)) {
      b = u;
      ans = val;
    }
  }

  auto buf = gen(bst);
  cout << build(buf).second;
}
