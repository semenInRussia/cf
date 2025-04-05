// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 6000;
int w[N];
int64_t ans[N];

const int64_t inf = 1e18 + 10;

vector<int> cur;
int64_t pen = 0;
int n;

void f() {
  int x = cur.back();
  ans[x - 1] = min(ans[x - 1], pen);

  set<int> s;

  // first: add 1
  if (x + 1 <= n) {
    s.insert(x + 1);
  }

  // second:
  for (int a : cur) {
    for (int b : cur) {
      if (1ll * a * b <= n && 1ll * a * b > x) {
        s.insert(a * b);
      }
    }
  }

  for (int v : s) {
    cur.push_back(v);
    pen += w[v - 1];
    f();
    pen -= w[v - 1];
    cur.pop_back();
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    ans[i] = +inf;
  }
  cur.push_back(1);
  pen += w[0];
  f();
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}
