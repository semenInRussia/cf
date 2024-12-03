// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
int a[N];
bool used[N];
vector<int> g[N];

void dfs(int x, int c) {
  used[x] = 1;
  a[c]++;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y, c);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i, cnt++);
    }
  }

  for (int i = 0; i < cnt; i++) {
    cout << a[i] << '\n';
  }
}
