// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int &x : a) {
      cin >> x;
    }
    auto it = find(a.begin(), a.end(), 1);
    if (it == a.end()) {
      a.push_back(1);
    } else {
      a.erase(it);
    }
    sort(a.begin(), a.end());
    cout << n << " " << a.size() << "\n";
    for (int x : a) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
