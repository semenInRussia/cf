// semenInRussia 2024
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

const int64_t N = 1e11 + 10;

int64_t pows(int64_t a, int64_t b, int64_t m) {
  int64_t ans = 1;
  while (b) {
    if (b & 1) {
      ans = (a * ans) % m;
    }
    b >>= 1;
    a = (a * a) % m;
  }
  return ans;
}

bool prime(int64_t x) {
  if (x == 2) {
    return true;
  }
  for (int i = 0; i < 50; i++) {
    int64_t a = (rand() % (x - 2)) + 2;
    if (gcd(a, x) != 1) {
      return false;
    }
    if (pows(a, x - 1, x) != 1) {
      return false;
    }
  }
  return true;
}

int main() {
  const int64_t S = 2584513177;
  // const int64_t S = 0;
  // const int64_t inf = 1e18 + 100;

  const int L = 4;
  const int xs[L] = {10, 20, 30, 40};

  pair<int64_t, pair<int64_t, int64_t>> ans[L];
  ans[1 - 1] = {1116452627 - 1116452663, {1116452627, 1116452663}};
  ans[2 - 1] = {1765088041 - 1765088179, {1765088041, 1765088179}};
  ans[3 - 1] = {1851213209 - 1851213473, {1851213209, 1851213473}};
  ans[4 - 1] = {1690476631 - 1690477037, {1690476631, 1690477037}};
  vector<int64_t> q;

  int c = 0;

  for (int64_t i = S; i < N; i++) {
    if (!prime(i)) {
      continue;
    }

    c++;

    if (c == 100'000) {
      c = 0;
      cout << "\n\n\nprint(*{";
      cout << "50: (1830405529, 1830406051),\n2: (1000000007, 1000000009),\n";
      for (int j = 0; j < L; j++) {
        auto [a, b] = ans[j].second;
        cout << xs[j] << ": (" << a << ", " << b << "), \n";
      }
      cout << "}[int(input())]) #" << i << "\n\n\n";
    }

    int k = (int)q.size();
    q.push_back(i);
    for (int j = 0; j < L; j++) {
      auto x = xs[j];
      if (k - x + 1 >= 0) {
        ans[j] = min(ans[j], {q[k] - q[k - x + 1], {q[k - x + 1], q[k]}});
      }
    }

    if (int(q.size()) >= xs[L - 1]) {
      q.erase(q.begin());
    }
  }

  cout << "\n\n\nprint(*{";
  cout << "50: (1830405529, 1830406051),\n2: (1000000007, 1000000009),\n";
  for (int j = 0; j < L; j++) {
    auto [a, b] = ans[j].second;
    cout << xs[j] << ": (" << a << ", " << b << "), \n";
  }
  cout << "}[int(input())]) #" << "end" << "\n\n\n";
}
