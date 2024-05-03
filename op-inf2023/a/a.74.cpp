// Copyright 2023 semenInRussia

using namespace std;

#include <climits>
#include <fstream>
#include <vector>

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
    int l = (t[0] - k) / m;

    size_t i = 0;
    int d = 0;

    while (i < n) {
      int p = (l + d + 1) * m + k;

      if (t[i] >= p) {
        break;
      }

      while (t[i] < p) {
        i++;
        if (i == n) {
          break;
        }
      }

      d++;
    }

    if (i >= n) {
      fout << k << endl;
      return 0;
    }
  }

  fout << "-1" << endl;

  return 0;
}
