// Copyright 2024 semenInRussia

#include <vector>
using namespace std;

#include <iostream>
using ull = unsigned long long;

const ull mod = 1e15 + 7, k = 3;
const int maxn = 2e5;
ull m[maxn];
int enc[64];

void fill_mods() {
  m[0] = 1;
  for (int i = 1; i < maxn; i++) {
    m[i] = (m[i - 1] * k) % mod;
  }
  enc['1'] = 2;
  enc['0'] = 1;
}

ull hash_string(const char *s, int n) {
  ull h = 0;
  for (int i = 0; i < n; i++) {
    int x = enc[s[i]];
    h = (h + x * m[i]) % mod;
  }
  return h;
}

ull hash_string(string &s) {
  const ull n = s.size();
  ull h = 0;
  for (int i = 0; i < n; i++) {
    int x = enc[s[i]];
    h = (h + x * m[i]) % mod;
  }
  return h;
}

ull remove_prefix(ull prefix, ull s, int prefix_n) {
  return (s - prefix) / m[prefix_n];
}

ull concat(ull a, ull b, int an) {
  //
  return (a + (b * m[an]) % mod) % mod;
}

void solve_first() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  cout << s << endl;
}

void solve_second() {
  int n;
  cin >> n;

  string t, s;
  cin >> t >> s;

  ull th = hash_string(t);
  // hs[i] is hash of t [0, i)
  vector<ull> hs(n + 1);
  hs[0] = 0;
  for (int i = 0; i < n; i++) {
    int x = enc[s[i]];
    hs[i + 1] = (hs[i] + x * m[i]) % mod;
  }

  // k is prefix len
  ull sh = hs.back();
  for (int k = 0; k < n; k++) {
    // s is a+b
    // check that b+a == t
    ull a = hs[k];
    ull b = remove_prefix(a, sh, k);

    if (concat(b, a, n - k) == th) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  string typ;
  cin >> typ;
  if (typ == "first") {
    solve_first();
  } else {
    fill_mods();
    solve_second();
  }
  return 0;
}
