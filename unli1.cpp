// semenInRussia 2024
// https://codeforces.com/problemset/problem/2009/G1
#include <iostream>
#include <map>
#include <set>
using namespace std;

const int N = 2e5 + 200, inf = 1e9 + 100;
int a[N], d[N], ans[N];

void solve() {
  int n,k,q;
  cin >> n >> k >> q;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // find d=a_i-(i-l)
  for (int i = 0; i < n; i++) {
    d[i] = a[i] - i;
  }

  // for every [i; i+k) maintain the count of element and choose the best
  // ans[i] is answer for [i; i+k)
  map<int, int> cnt;
  multiset<int> vars;

  auto add = [&cnt, &vars](int x) {
    if (cnt[x]) {
      vars.erase(vars.find(cnt[x]));
    }
    cnt[x]++;
    vars.insert(cnt[x]);
  };

  auto rem = [&cnt, &vars](int x) {
    int k = cnt[x];
    if (k) {
      vars.erase(vars.find(k));
    }
    cnt[x]--;
    k--;
    if (k) {
      vars.insert(k);
    }
  };

  for (int i = 0; i < k; i++) {
    add(d[i]);
  }

  for (int l = 0; l + k <= n; l++) {
    ans[l] = k - *vars.rbegin();
    rem(d[l]);
    add(d[l+k]);
  }

  cout << "\n";
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << ans[l] << '\n';
  }
}

int main() {
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}
