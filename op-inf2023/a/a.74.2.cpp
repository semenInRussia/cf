// Copyright 2023 semenInRussia

using namespace std;

#include <fstream>
#include <vector>

#define day(t) ((t - k) / m)

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  size_t n;
  int m;
  fin >> n >> m;

  vector<int> t(n);

  for (size_t i = 0; i < n; i++) {
    fin >> t[i];
  }

  for (int k = 0; k < m; k++) {
    // check day from i to n-2,
    // d[i+1] - d[i]
    //
    // d[i] = (t[i] - k) / m
    bool ok = true;

    for (size_t i = 0; i < n - 1; i++) {
      int dist = day(t[i + 1]) - day(t[i]);
      if (dist < 0 || dist > 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      fout << k << endl;
      return 0;
    }
  }

  fout << "-1" << endl;

  return 0;
}
