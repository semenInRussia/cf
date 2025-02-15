// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int64_t inf = 1e18 + 1000;
const int N = 105, A = 2005;

bool f[N][A][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> y(n);

  for (int &x : y) {
    cin >> x;
  }

  // (i, s, k)
  // (j, s', k'): sum(j:i) | f(j, s', k-1)
}
