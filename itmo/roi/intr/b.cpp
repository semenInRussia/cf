// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
const int L = 31 + 64;

struct mi {
  int a; // 1e9 + 7
  uint64_t b;

  mi() {}
  mi(int x) : a(x), b(x) {}
  mi(int x, uint64_t y) : a(x), b(y) {}
};

mi operator*(mi x, mi y) {
  return {
      int((1ll * x.a * y.a) % mod),
      x.b * y.b,
  };
}

mi operator+(mi x, mi y) {
  return {
      (x.a + y.a) % mod,
      x.b + y.b,
  };
}

mi operator-(mi x, mi y) {
  return {
      (x.a - y.a + mod) % mod,
      x.b - y.b,
  };
}

bool operator==(mi x, mi y) { return x.a == y.a && x.b == y.b; }
mi &operator+=(mi &v, mi a) { return v = v + a; }
mi &operator-=(mi &v, mi a) { return v = v - a; }

mi read(string &s) {
  int a = 0;
  for (int i = 0; i < 31; i++) {
    int c = s[i] - '0';
    a += (1 << i) * c;
  }
  uint64_t b = 0;
  for (int i = 0; i < 64; i++) {
    int c = s[i + 31] - '0';
    if (c) {
      b |= 1ull << i;
    }
  }
  return {a, b};
}

string write(mi v) {
  string s = "";
  for (int i = 0; i < 31; i++) {
    s += '0' + ((v.a >> i) & 1);
  }
  for (int i = 0; i < 64; i++) {
    s += '0' + ((v.b >> i) & 1);
  }
  return s;
}

const int N = 5e5;
mi p[N];

// begin score=55

void solve1(string s) {
  string p = "";
  for (auto c : s) {
    p += c;
    p += c;
    p += c;
  }
  cout << p;
}

void solve2(string s) {
  int n = (int)s.size() / 3;
  string p = "";
  for (int i = 0; i < n; i++) {
    char a = s[3 * i] - '0' + s[3 * i + 1] - '0' + s[3 * i + 2] - '0';
    p += (a <= 1 ? '0' : '1');
  }
  cout << p;
}

// end score=55

int ord(char c) { return c - '0' + 1; }

string s1(string s) {
  mi h = 0;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    h += p[i] * ord(s[i]);
  }

  auto w = write(h);
  assert(read(w) == h);
  s += write(h);
  s += write(h);
  return s;
}

mi h[N];
string s2(string s) {
  int n = (int)s.size();
  string suf1 = s.substr(n - L);
  string suf2 = s.substr(n - 2 * L, L);

  n -= 2 * L;
  for (int i = 0; i < 2 * L; i++) {
    s.pop_back();
  }

  if (suf1 != suf2) {
    return s;
  }

  for (int i = 0; i < n; i++) {
    h[i + 1] = h[i] + p[i] * ord(s[i]);
  }

  mi ex = read(suf1);

  if (h[n] == ex) {
    return s;
  }

  for (int i = 0; i < n; i++) {
    mi cur = h[i];
    cur += h[n] - h[i + 1];
    cur += p[i] * (3 - ord(s[i]));
    if (cur == ex) {
      s[i] = '0' + '1' - s[i];
      return s;
    }
  }

  assert(0 && "unrech!");
  return "";
}

#ifdef home
int main() {
  // stress testing
  string s = "";
  int n = 1e5;
  for (int i = 0; i < n; i++) {
    s += (i & 1) + '0';
  }

  p[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    p[i] = p[i - 1] * 5;
  }

  string d = s1(s);

  for (int i = 0; i < n; i++) {
    if (i % 5000 == 0) {
      cout << i << ".\n";
    }
    d[i] = '0' + '1' - d[i];
    assert(s2(d) == s);
    d[i] = '0' + '1' - d[i];
  }
}
#else
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int typ;
  cin >> typ;
  string s;
  cin >> s;

  int n = (int)s.size();

  p[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    p[i] = p[i - 1] * 5;
  }

  if (n < 30 && typ == 1) {
    solve1(s);
  } else if (n <= 30 && typ == 2) {
    solve2(s);
  } else if (typ == 1) {
    cout << s1(s);
  } else {
    cout << s2(s);
  }
}
#endif
