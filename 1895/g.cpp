// Copyright 2023 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

void tc() {
  size_t n;
  cin >> n;

  vector<bool> s(n);

  for (size_t i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    s[i] = ch == '1';
  }

  vector<size_t> b(n), r(n);

  for (size_t i = 0; i < n; i++) {
    cin >> r[i];
  }

  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }

  size_t ans = 0;
  bool started = false;
  bool col = false;
  size_t invs = 0;

  for (size_t i = 0; i < n; i++) {
    int bi = b[i];
    int ri = r[i];

    if (bi >= ri) {
      ans += bi;
      continue;
    }

    ans += ri;

    if (!started) {
      started = true;
      col = s[i];
      cout << "change a col to " << col << endl;
      continue;
    }

    if (col == 1 && s[i] == 0) {
      invs++;
    }

    col = s[i];
    cout << "change a col to " << col << endl;
  }

  cout << ans << ':' << ans - invs << endl;
}

int main() {
  size_t n;
  cin >> n;

  while (n--) {
    tc();
  }

  return 0;
}
