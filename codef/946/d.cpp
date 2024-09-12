// 2024 semenInRussia
#include <iostream>
using namespace std;
using ll = long long;

int cnt[1000];
bool check(int X, int Y, int &da, int &db, int &dc, int &dd, int time = 1) {
  da = -1, db = -1, dc = -1, dd = -1;
  bool ok = false;
  for (int a = 0; a <= X; a++) {
    int b = X - a;
    int d2 = b + Y - a;
    if (d2 & 1 || d2 < 0 || (d2 / 2) > Y)
      continue;
    int d = d2 / 2;
    int c = Y - d;
    if (a - c == b - d) {
      ok = true;
      da = a, db = b, dc = c, dd = d;
      if ((a + c) && (b + d))
        return true;
    }
  }
  if (time == 2) {
    // a,c <=> b,d
    swap(da, db);
    swap(dc, dd);
  }
  return ok;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  fill(cnt, cnt + 1000, 0);
  for (int i = 0; i < n; i++)
    cnt[s[i]]++;

  // first is north and south
  int ans[1000][1000];
  fill(ans['H'], ans['H'] + 1000, 0);
  fill(ans['R'], ans['R'] + 1000, 0);

  int ok = 0;
  ok += check(cnt['S'], cnt['N'], ans['H']['S'], ans['R']['S'], ans['H']['N'],
              ans['R']['N']);

  ok += check(cnt['W'], cnt['E'], ans['H']['W'], ans['R']['W'], ans['H']['E'],
              ans['R']['E'], 2);

  if (ok < 2 ||
      (ans['R']['E'] + ans['R']['S'] + ans['R']['N'] + ans['R']['W'] == 0) ||
      (ans['H']['E'] + ans['H']['S'] + ans['H']['N'] + ans['H']['W'] == 0)) {
    cout << "NO\n";
    return;
  }

  for (auto ch : s) {
    if (ans['H'][ch])
      ans['H'][ch]--, cout << "H";
    else if (ans['R'][ch])
      ans['R'][ch]--, cout << "R";
  }
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
