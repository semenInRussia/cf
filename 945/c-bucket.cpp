// Copyright 2024 BucketPotato

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
      cin >> i;

    int wi = (find(a.begin(), a.end(), n) - a.begin()) % 2;

    vector<pair<int, int>> good;
    for (int i = wi; i < n; i += 2)
      good.push_back({a[i], i});
    vector<pair<int, int>> bad;
    for (int i = (wi ^ 1); i < n; i += 2)
      bad.push_back({a[i], i});

    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end());
    reverse(good.begin(), good.end());
    reverse(bad.begin(), bad.end());

    vector<int> ans(n);
    int cv = 1;
    for (auto [_, ind] : bad)
      ans[ind] = cv++;
    for (auto [_, ind] : good)
      ans[ind] = cv++;

    for (int i = 0; i < n; i++)
      cout << ans[i] << " \n"[i + 1 == n];
  }
}
