// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 50 * 3 + 10;
// const int N = 10;
bool a[N][N], b[N][N];

void petya() {
  int n;
  cin >> n;

  // a (2n) => b (3n)

  for (int i = 0; i < (2 * n); i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (2 * n); j++) {
      int c = s[j] - '0';
      a[i][j] = c;
    }
  }

  int bi = 0, bj = 0;

  auto add = [&bi, &bj, n](int x) {
    b[bi][bj] = b[bj][bi] = x;
    bj++;
    if (bj == 3 * n) {
      bi++;
      bj = bi;
    }
  };

  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      add(a[i][j]);
    }
  }
  for (int i = 0; i < 3 * n; i++) {
    for (int j = 0; j < 3 * n; j++) {
      cout << b[i][j];
    }
    cout << '\n';
  }
}

void natasha() {
  int n;
  cin >> n;

  // a (3n) => b (2n)

  for (int i = 0; i < (3 * n); i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (3 * n); j++) {
      a[i][j] = s[j] - '0';
    }
  }

  int ai = 0, aj = 0;

  auto pop = [&ai, &aj, n]() {
    int ans = a[ai][aj];
    aj++;
    if (aj == 3 * n) {
      ai++;
      aj = ai;
    }
    return ans;
  };

  for (int i = 0; i < (2 * n); i++) {
    for (int j = 0; j < (2 * n); j++) {
      b[i][j] = pop();
    }
  }
  for (int i = 0; i < (2 * n); i++) {
    for (int j = 0; j < (2 * n); j++) {
      cout << b[i][j];
    }
    cout << '\n';
  }
}

int main() {
  string who;
  cin >> who;
  if (who == "Petya") {
    petya();
  } else {
    natasha();
  }
}
