// Copyright (C) 2024 by semenInRussia

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ull = unsigned long long;

unordered_map<ull, int> h;
unordered_set<ull> nums;

const ull M = (1ULL << 31ULL) - 1ULL;

void rem(ull el) {
  h[el]--;
  if (!h[el])
    h.erase(el);
}

void solve() {
  int n;
  cin >> n;
  h.clear();
  nums.clear();

  for (int i = 0; i < n; i++) {
    ull x;
    cin >> x;
    nums.insert(x);
    if (h.count(x)) {
      h[x]++;
    } else {
      h[x] = 1;
    }
  }

  int ans = 0;

  for (auto num : nums) {
    ans += max(h[num], h[num ^ M]);
    h[num ^ M] = 0;
    h[num] = 0;
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  h.rehash(2e5 + 10);
  nums.rehash(2e5 + 10);

  while (t--)
    solve();

  return 0;
}
