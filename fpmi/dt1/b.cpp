// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 60;
int m[N][N];

int n;

bool ask() {
  cout << "?" << endl;

  for (int i = 0; i < n; i++) {
    string s;
    for (int j = 0; j < n; j++) {
      s += m[i][j] + '0';
    }
    cout << s << endl;
  }

  int x;
  cin >> x;
  assert(x != -1);
  return x;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i][j] = 1;
    }
  }

  int a = -1;

  // first guess row;
  for (int i = 1; i < n - 1; i++) {
    fill(m[i], m[i] + n, 0);
    bool ok = ask();
    if (ok) {
      a = i;
      break;
    }
    fill(m[i], m[i] + n, 1);
  }

  int l = -1;
  int r = n;

  while (r - l > 1) {
    int k = (l + r) / 2;
    for (int i = 0; i < a; i++) {
      for (int j = k + 1; j < n; j++) {
        m[i][j] = 0;
      }
    }
    bool ok = ask();
    for (int i = 0; i < a; i++) {
      for (int j = k + 1; j < n; j++) {
        m[i][j] = 1;
      }
    }
    if (ok) {
      r = k;
    } else {
      l = k;
    }
  }

  cout << "!" << endl;
  cout << a << " " << r << endl;
  int x;
  cin >> x;
  assert(x != -1);
}

int main() {
  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }
}
