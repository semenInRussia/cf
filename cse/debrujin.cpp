// semenInRussia 2024
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 1 << 15;
multiset<int> g[N];

void remove(int x, int y) { g[x].erase(g[x].find(y)); }

vector<int> order;
void euler(int x) {
  while (!g[x].empty()) {
    int y = *g[x].begin();
    remove(x, y);
    euler(y);
  }
  order.push_back(x);
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "01";
    return 0;
  }

  for (int x = 0; x < (1 << (n - 1)); x++) {
    int y = (x << 1) & ((1 << (n - 1)) - 1);
    g[x].insert(y);
    g[x].insert(y | 1);
  }

  euler(0);

  // make amount of zeroes at the end = n
  while (!order.empty() && order.back() == 0) {
    order.pop_back();
  }
  for (int i = 0; i < n; i++) {
    order.push_back(0);
  }

  for (int x : order) {
    cout << (x & 1);
  }
}
