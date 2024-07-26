// semenInRussia 2024
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const int N = 2.1e5;
int a[N], b[N];
using pii = pair<int, int>;

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  priority_queue<pii> q;
  for (int i = 0; i < n; i++)
    q.push({a[i], -b[i]});
  q.push({0, 0});
  ll ans = 0;
  while (k) {
    auto tp = q.top();
    q.pop();
    if (tp.first == 0)
      break;
    auto snd = q.top();
    int bi = -tp.second;
    ll g = min(tp.first / bi, ((tp.first - snd.first) / bi));
    g = max(1ll, g);
    g = min((ll)k, g);
    ll l = tp.first - g * bi;
    ll r = tp.first;
    ans += ((l + r) * g) / 2;
    k -= g;
    tp.first = max(tp.first - 1ll * g * bi, 0ll);
    q.push(tp);
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
