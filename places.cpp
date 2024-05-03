#include <bits/stdc++.h>
const int inf = INT32_MAX;

using namespace std;

struct Friend {
  int w, h, id;
};

int last_i(vector<Friend> &a, int w) {
  int l = -1, r = (int)a.size();
  // last i: w[i] < f.w
  while (r > l + 1) {
    int mid = (r + l) / 2;
    if (a[mid].w < w)
      l = mid;
    else
      r = mid;
  }

  return l;
}

void solve() {
  int n;
  cin >> n;
  vector<Friend> a(n);
  int t = 0;
  for (auto &f : a) {
    cin >> f.w >> f.h;
    f.id = t++;
  }

  sort(a.begin(), a.end(), [](auto a, auto b) { return a.w < b.w; });

  vector<Friend> p(n);
  auto mn = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i].h < mn.h)
      mn = a[i];
    p[i] = mn;
  }

  vector<int> answers(n, -1);

  for (auto f : a) {
    for (int axis : {1, 2}) {
      int i = last_i(a, f.w);
      i = max(i, 0);
      i = min(i, n - 1);
      Friend mb = p[i];

      if (mb.h < f.h && mb.w < f.w)
        answers[f.id] = mb.id + 1;

      swap(f.w, f.h);
    }
  }

  for (auto x : answers)
    cout << x << ' ';
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
