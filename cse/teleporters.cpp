// semenInRussia 2024
// https://cses.fi/problemset/task/1693
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
vector<int> g[N];
int in[N], out[N];

vector<int> answ;
void euler(int x) {
  while (!g[x].empty()) {
    int y = g[x].back();
    g[x].pop_back();
    euler(y);
  }
  answ.push_back(x);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    out[a]++, in[b]++;
  }

  bool ok = true;
  for (int x = 1; x < n - 1 && ok; x++) {
    if (in[x] != out[x]) {
      ok = false;
    }
  }

  bool bad = out[0] != in[0] + 1 || out[n - 1] != in[n - 1] - 1 || !ok;

  if (!bad) {
    euler(0);
    reverse(answ.begin(), answ.end());
  }

  if (answ.empty() || (answ.back() != (n - 1) || answ.size() != m + 1)) {
    bad = true;
  }

  if (bad) {
    cout << "IMPOSSIBLE";
  } else {
    for (int x : answ) {
      cout << (x + 1) << ' ';
    }
  }
}
