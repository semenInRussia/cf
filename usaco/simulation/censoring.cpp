// Copyright 2024 semenInRussia

// an USACO problem (Old Bronze) at the link
//
// https://usaco.org/index.php?page=viewproblem2&cpid=526

// it has a label "Hard"

// start 16:27

using namespace std;
#include <fstream>

bool endswith(string &s, string &t) {
  int tn = t.size(), sn = s.size();
  return sn >= tn && s.substr(sn - tn, tn) == t;
}

int main() {
  ifstream cin("censor.in");
  ofstream cout("censor.out");

  string t, s;
  cin >> s >> t;

  string ns = "";

  for (auto ch : s) {
    ns += ch;
    if (endswith(ns, t))
      ns.resize(ns.size() - t.size());
  }

  cout << ns << '\n';

  return 0;
}
