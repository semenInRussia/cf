// semenInRussia 2024
// https://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=345&id_problem=2239
#include <cstdint>
#include <iostream>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int N = 4e5;
int b[N];
int incr[N], decr[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  // inc[i] - last index that [i; j] - increasing sequence
  // dec[i] - last index that [i; j] - decreasing sequence

  int r = 0;
  for (int l = 0; l < n; l++) {
    r = max(l, r);
    while (r + 1 < n && b[r + 1] > b[r]) {
      r++;
    }
    incr[l] = r;
  }

  r = 0;
  for (int l = 0; l < n; l++) {
    r = max(l, r);
    while (r + 1 < n && b[r + 1] < b[r]) {
      r++;
    }
    decr[l] = r;
  }

  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    int j = decr[incr[i]];
    // cout << "for " << i << " " << j << "\n";
    ans += j - i + 1;
  }

  cout << ans;
}
