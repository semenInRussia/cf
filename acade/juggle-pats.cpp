#include <iostream>
#include <set>

using namespace std;

int check1(string &s) {
  int sum = 0;
  for (char c : s) {
    sum += c - '0';
  }
  if (sum % int(s.size()) == 0) {
    return sum / int(s.size());
  }
  return -1;
}

bool check2(string &s) {
  set<int> m;
  int n = (int)s.size();
  for (int i = 0; i < 10 * n; i++) {
    auto d = (s[i % n] - '0') + i + 1;
    if (m.count(d)) {
      return false;
    }
    m.insert(d);
  }
  return true;
}

void solve(string &s) {
  int x = check1(s);
  cout << s << ": ";
  if (x == -1) {
    cout << "invalid # of balls\n";
  } else if (!check2(s)) {
    cout << "invalid pattern\n";
  } else {
    cout << "valid with " << x << " balls\n";
  }
}

int main() {
  string s;
  while (cin >> s) {
    solve(s);
  }
}
