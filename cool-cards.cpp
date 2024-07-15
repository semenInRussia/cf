// semenInRussia 2024
// https://codeforces.com/problemset/problem/1992/F
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 2e5;
int a[N];
void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0;
  unordered_set<int> p;
  vector<int> toadd;
  for (int i = 0; i < n;) {
    // check [i;j]
    p.clear();
    p.insert(1);
    int j;
    int br = false;
    for (j = i; j < n && !br; j++) {
      if (x % a[j])
        continue;
      if (p.count(x / a[j]))
        br = true;
      for (auto e : p)
        if (e * a[j] < x)
          toadd.push_back(a[j] * e);
      for (auto e : toadd)
        p.insert(e);
      toadd.clear();
    }
    i = br ? j - 1 : j + 1;
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
