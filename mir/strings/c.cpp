// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

bool is_integer(string &s) {
  if (s.empty())
    return false;

  for (auto ch : s) {
    if (ch > '9' || ch < '0') {
      return false;
    }
  }
  // we know that every symbol is digit, check that the string isn't
  // string with extra leading zeroes
  return s.size() == 1 || s[0] != '0';
}

int main() {
  string s;
  cin >> s;

  vector<string> words;

  string a = ""; // they without quotes
  string b = "";

  string cur_word = "";
  for (int i = 0; true; i++) {
    cur_word = "";
    // read a word until ,
    while (i < s.size() && s[i] != ';' && s[i] != ',') {
      cur_word += s[i];
      i++;
    }

    // cout << '"' << cur_word << '"' << endl;

    if (is_integer(cur_word)) {
      a += cur_word;
      a += ',';
    } else {
      b += cur_word;
      b += ',';
    }

    if (i >= s.size())
      break;
  }

  if (a.empty()) {
    cout << "-" << endl;
  } else {
    a.erase(a.size() - 1); // chop the last ,
    cout << "\"" << a << '"' << endl;
  }

  if (b.empty()) {
    cout << "-" << endl;
  } else {
    b.erase(b.size() - 1); // chop the last ,
    cout << "\"" << b << '"' << endl;
  }
}
