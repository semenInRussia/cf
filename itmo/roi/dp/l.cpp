// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 12;
string t[N];
int p[N];
int64_t f1[46656], f2[46656];

const int inf = 1e9;

inline int get(int x, int j) { return (x / p[j]) % 6; }

template <typename T> T &setmin(T &v, T op) { return v = min(v, op); }

int n, m;

bool canh(int i, int j) {
  if (j + 5 > m) {
    return false;
  }
  for (int l = j; l < j + 5; l++) {
    if (t[i][l] == '.') {
      return false;
    }
  }
  return true;
}

bool canv(int i, int j) {
  if (i + 5 > n) {
    return false;
  }
  for (int l = i; l < i + 5; l++) {
    if (t[l][j] == '.') {
      return false;
    }
  }
  return true;
}

int addh(int b, int i) {
  while (get(b, i) < 5) {
    b += p[i];
  }
  return b;
}

int addv(int b, int i) {
  for (int l = i; l < i + 5; l++) {
    if (get(b, l) == 0) {
      b += p[l];
    }
  }
  return b;
}

string disp(int x) {
  string s(5, '0');
  for (int j = 0; j < 5; j++) {
    s[j] = get(x, j) + '0';
  }
  return s;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("fivestar.in", "r", stdin);
  freopen("fivestar.out", "w", stdout);
#endif
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  p[0] = 1;
  for (int i = 0; i + 1 < N; i++) {
    p[i + 1] = p[i] * 6;
  }

  for (int i = 0; i < p[n]; i++) {
    f2[i] = f1[i] = +inf;
  }
  f1[0] = 0;

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      for (int b = 0; b < p[n]; b++) {
        if (t[i][j] == '.') {
          setmin(f2[b], f1[b]);
          continue;
        }

        // do nothing
        if (get(b, i) >= 1) {
          setmin(f2[b], f1[b]);
        }

        // add vertical
        // if [i, i+5) == '*'
        if (canv(i, j)) {
          setmin(f2[addv(b, i)], f1[b] + 1);
        }

        // add horizontal
        // if [j; j+5)
        if (canh(i, j)) {
          setmin(f2[addh(b, i)], f1[b] + 1);
        }

        // add both
        if (canv(i, j) && canh(i, j)) {
          setmin(f2[addv(addh(b, i), i)], f1[b] + 2);
        }
      }

      for (int b = 0; b < p[n]; b++) {
        f1[b] = f2[b];
        f2[b] = +inf;
      }
    }

    // new line
    for (int b = 0; b < p[n]; b++) {
      int b2 = b;
      for (int i = 0; i < n; i++) {
        if (get(b, i) > 0) {
          b2 -= p[i];
        }
      }
      setmin(f2[b2], f1[b]);
    }

    for (int b = 0; b < p[n]; b++) {
      f1[b] = f2[b];
      f2[b] = +inf;
    }
  }

  cout << (f1[0] == +inf ? -1 : f1[0]);
}
