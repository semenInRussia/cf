// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 100;
int p[N], a[N];

int main() {
  int n, e;
  cin >> n >> e;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = i;
  }

  int ans = 0;

  int A = *min_element(a, a + n);

  do {
    // check n
    int64_t sum = 0;
    for (int i = 0; i + 1 < n; i++) {
      sum += a[p[i]] % a[p[i + 1]];
    }
    ans += sum <= A + e;
  } while (next_permutation(p, p + n));

  cout << ans << "\n";
}
