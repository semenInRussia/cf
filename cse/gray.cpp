// semenInRussia 2024
// https://cses.fi/problemset/task/2205
#include <iostream>
#include <vector>
using namespace std;

void f(vector<int> &res, int n) {
  if (n == 1) {
    res.push_back(0);
    res.push_back(1);
    return;
  }
  f(res, n - 1);
  int sz = int(res.size());
  for (int i = sz - 1; i >= 0; i--) {
    res[i] <<= 1;
    res.push_back(res[i] | 1);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> res;
  f(res, n);
  for (int num : res) {
    for (int j = 0; j < n; j++)
      cout << ((num >> j) & 1);
    cout << '\n';
  }
}
