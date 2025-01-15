// semenInRussia 2024
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<pair<int, int>, int> memo;

int qry(int l, int r) {
  if (l == r) {
    return 0;
  }

  auto &ans = memo[{l, r}];

  if (ans != 0) {
    return ans;
  }

  cout << "? " << (l + 1) << " " << (r + 1) << endl;
  cin >> ans;

  return ans;
}

const int N = 5005;
int answ[N];
bool used[N];

int nxt(int x, int y, int d1, int d2, int d3) {
  if (x > y) {
    if (d1 == d3 || d2 == d3) {
      return d2 + y;
    }
    return y - d2;
  }

  if (d1 == d3 || d2 == d3) {
    return y - d2;
  }
  return d2 + y;
}

int main() {
  int n;
  cin >> n;

  int d = n - 1;

  // find last j; qry(j, n)=d

  int l = -1;
  int r = n - 1;

  int pos = -1;

  while (r - l > 1) {
    int m = (r + l) / 2;
    if (qry(m, n - 1) == d) {
      l = m;
    } else {
      r = m;
    }
  }

  pos = l;

  int mn = 1;

  answ[pos] = mn;
  answ[pos + 1] = qry(pos, pos + 1) + 1;

  used[answ[pos]] = 1;
  used[answ[pos + 1]] = 1;

  for (int i = pos; i + 2 < n; i++) {
    int x = answ[i];
    int y = answ[i + 1];

    int d2 = qry(i + 1, i + 2);

    if (y - d2 <= 0 || used[y - d2]) {
      answ[i + 2] = y + d2;
      used[y + d2] = 1;
      continue;
    }

    if (y + d2 > n || used[y + d2]) {
      answ[i + 2] = y - d2;
      used[y - d2] = 1;
      continue;
    }

    int d1 = qry(i, i + 1);
    int d3 = qry(i, i + 2);

    answ[i + 2] = nxt(x, y, d1, d2, d3);
    used[answ[i + 2]] = 1;
  }

  for (int i = pos - 1; i >= 0; i--) {
    int y = answ[i + 1];
    int x = answ[i + 2];

    int d2 = qry(i, i + 1);

    if (y - d2 <= 0 || used[y - d2]) {
      answ[i] = d2 + y;
      used[d2 + y] = 1;
      continue;
    }

    if (d2 + y > n || used[d2 + y]) {
      answ[i] = y - d2;
      used[y - d2] = 1;
      continue;
    }

    int d3 = qry(i, i + 2);
    int d1 = qry(i + 1, i + 2);

    answ[i] = nxt(x, y, d1, d2, d3);
    used[answ[i]] = 1;
  }

  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << answ[i] << " ";
  }
  cout << endl;
}
