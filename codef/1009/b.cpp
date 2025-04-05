// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <queue>

using namespace std;

// a + b > c
// a + c > b
// c > b - a
// c > a - b

// c > than diff
// c < sum
// c = a + b - 1
// a + b - 1 < a - b

void solve() {
  priority_queue<int64_t> q;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }
  while (q.size() > 1) {
    auto a = q.top();
    q.pop();
    auto b = q.top();
    q.pop();
    q.push(a + b - 1);
  }
  cout << q.top() << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
