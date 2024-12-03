// semenInRussia 2024
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e3;
int t[N][N], s[N][N];

int n;

using ll = long long;
vector<ll> p; // sums on sides, top, right, bottom, left
vector<ll> c; // corners (0, 0), (0, m-1), (n-1,m-1), (n-1,0)

void turn90() {
  ll b = p.back();
  p.pop_back();
  p.insert(p.begin(), b);
  // --
  b = c.back();
  c.pop_back();
  c.insert(c.begin(), b);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t[i][j];
    }
  }
  // top
  p.push_back(0);
  for (int j = 0; j < n; j++) {
    p.back() += t[0][j];
  }

  // rigt
  p.push_back(0);
  for (int j = 0; j < n; j++) {
    p.back() += t[j][n - 1];
  }

  // bottom
  p.push_back(0);
  for (int j = 0; j < n; j++) {
    p.back() += t[n - 1][j];
  }

  // left
  p.push_back(0);
  for (int j = 0; j < n; j++) {
    p.back() += t[j][0];
  }

  // vector<ll> c; // corners (0, 0), (0, m-1), (n-1,m-1), (n-1,0)
  c.push_back(t[0][0]);
  c.push_back(t[0][n - 1]);
  c.push_back(t[n - 1][n - 1]);
  c.push_back(t[n - 1][0]);

  //
  int k;
  cin >> k;
  int a = 0; // angle
  int v[4]{+90, -90, +45, -45};
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    a += v[c - 1];
  }
  a %= 360;
  if (a < 0) {
    a += 360;
  }
  while (a >= 90) {
    a -= 90;
    turn90();
  }

  assert(a == 0 || a == 45);
  if (a) {
    cout << c[3] << ' ' << c[1];
    return 0;
  }

  cout << p[3] << ' ' << p[1];
}
