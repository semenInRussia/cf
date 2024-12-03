// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
int bad[N]; // index on jam

int x;

vector<int> ans;

// return { amount of bad jams, sum of their xs }
pair<int, int> solve(int v[3]) {
  ans.clear();
  int l = 0;
  int t = 0;
  int s = 0;
  while (l < x) {
    int r = l + v[t % 3];
    // cout << "Check (" << l << ", " << r << ")\n";
    if (r >= x) {
      break;
    }
    t++;
    if ((r < x && bad[r] >= 0 && bad[r] == bad[r - 1])) {
      if (ans.size() && ans.back() == bad[l]) {
        continue;
      }
      ans.push_back(bad[r]);
      s += bad[l];
    }
    l = r;
  }
  return {int(ans.size()), s};
}

int main() {
  cin >> x;
  int a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  fill(bad, bad + x, -1);
  for (int i = 0; i < n; i++) {
    int x0, sz;
    cin >> x0 >> sz;
    int l = x0;
    int r = x0 + sz;
    for (int j = l; j < r; j++) {
      bad[j] = x0;
    }
  }

  int vs[3][3] = {{a, b, b}, {b, a, b}, {b, b, a}};
  pair<pair<int, int>, int> bst = {{n * 2, 0}, 0};
  for (int i = 0; i < 3; i++) {
    bst = min(bst, {solve(vs[i]), i});
  }
  solve(vs[bst.second]);
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << '\n';
  }
}
