// semenInRussia 2025
#include <cstdint>
#include <iostream>

// #pragma GCC optimize("O3,unroll-loops,conserve-stack")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

using ii = uint32_t;

const int N = (1 << 24) + 1;
ii pref[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  ii a, b; // даны во входных данных
  cin >> a >> b;
  ii cur = 0; // беззнаковое 32-битное число

  auto nextRand = [&]() -> ii {
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8;   // число от 0 до 2
  };

  for (int i = 0; i < n; i++) {
    ii add = nextRand(); // число, которое нужно прибавить
    ii l = nextRand();
    ii r = nextRand();
    if (l > r)
      swap(l, r); // получили отрезок [l..r]

    // cout << l << " " << r << " += " << add << "\n";
    pref[l] += add;
    pref[r + 1] -= add;
  }

  // sum on [0; i] = a[i]

  ii val = 0;

  for (int i = 0; i < N; i++) {
    val += pref[i];
    pref[i] = val;
  }

  for (int i = 1; i < N; i++) {
    pref[i] += pref[i - 1];
  }

  for (int j = N - 2; j >= 0; j--) {
    pref[j + 1] = pref[j];
  }
  pref[0] = 0;

  uint32_t ans = 0;

  for (int i = 0; i < m; i++) {
    auto l = nextRand();
    auto r = nextRand();
    if (l > r)
      swap(l, r); // получили отрезок [l..r]

    // cout << "get sum " << l << " " << r << "\n";
    ans += pref[r + 1] - pref[l];
  }

  cout << "\n" << ans;

  return 0;
}
