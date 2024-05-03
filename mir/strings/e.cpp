// Copyright 2024 semenInRussia

using namespace std;

#include <iostream>

int main() {
  string s;
  cin >> s;
  int dot = s.size();
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '.') {
      dot = i;
      break;
    }
  }

  // first non-zero digit
  int fst = -1;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] != '.' && s[i] != '0') {
      fst = i;
      break;
    }
  }

  // must; dot - fst = 1
  int e = dot - fst;
  if (e > 0)
    e--;

  // chop '.' and '0' at right
  while (s.back() == '.' || s.back() == '0') {
    s.erase(s.size() - 1);
  }

  cout << s[fst];

  bool should_dot = true;
  for (int i = fst + 1; i < (int)s.size(); i++) {
    if (s[i] != '.') {
      if (should_dot) {
        should_dot = false;
        cout << '.';
      }
      cout << s[i];
    }
  }

  if (e)
    cout << "E" << e;

  cout << endl;
}
