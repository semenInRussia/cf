// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int idx = 1;
vector<int> p = {0, 1, 0, 1, 1, 1, 1};

#ifndef home

bool ask(int j) {
  ++idx;
  cout << "? " << (j + 1) << endl;
  int p;
  cin >> p;
  assert(idx <= 150);
  return p;
}

void answer(vector<int> &ans) {
  cout << "! ";
  for (int x : ans) {
    cout << x;
  }
  cout << endl;
  char c;
  cin >> c;
  assert(c == 'Y');
}

#else

bool ask(int j) {
  if (idx % 10 == 1) {
    // invert
    if (rand() % 2 == 0) {
      cerr << "invert\n";
      for (auto &x : p) {
        x ^= 1;
      }
    }
    if (rand() % 2 == 0) {
      cerr << "reverse\n";
      reverse(p.begin(), p.end());
    }
  }
  cout << "? " << (j + 1) << "\n";
  cout << p[j] << "\n";
  ++idx;
  return p[j];
}

void answer(vector<int> &ans) {
  cout << "! ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  assert(ans == p);
  cout << "OK!";
}

#endif

void solve(int n) {
  vector<int> ans(n, -1), eq, neq;
  idx = 1;
  int m = n / 2;

  auto clear = [&]() {
    // if neq other, xor every other
    if (!neq.empty()) {
      if (ask(neq[0]) != ans[neq[0]]) {
        for (int j : neq) {
          ans[j] ^= 1;
          ans[n - j - 1] ^= 1;
        }
      }
    }
    // if eq other, xor every other
    if (!eq.empty()) {
      if (ask(eq[0]) != ans[eq[0]]) {
        for (int j : eq) {
          ans[j] ^= 1;
          ans[n - j - 1] ^= 1;
        }
      }
    }
  };

  for (int j = 0; j < m; j++) {
    int ix = idx;
    ans[j] = ask(j);
    ans[n - j - 1] = ask(n - j - 1);
    if (ix % 10 <= 1 && j != 0) { // was shit
      if (ix % 10 == 0) {
        ans[j] = ask(j);
      }
      clear();
    }
    if (ans[j] == ans[n - j - 1]) {
      eq.push_back(j);
    } else {
      neq.push_back(j);
    }
  }

  if (ans[m] == -1) {
    bool bad = idx % 10 == 1;
    ans[m] = ask(m);
    if (bad) {
      clear();
    }
  }

  answer(ans);
}

int main() {
  int tt, n;

#ifdef home
  tt = 10000;
  n = rand() % 100;
  p.resize(n);
  for (int &x : p) {
    x = rand() % 2;
  }
#endif

#ifndef home
  cin >> tt >> n;
#endif
  while (tt--) {
#ifdef home
    n = rand() % 100;
    p.resize(n);
    for (int &x : p) {
      x = rand() % 2;
    }
#endif
    solve(n);
    // cerr << "idx: " << idx << "\n";
  }
}
