// Copyright 2024 semenInRussia

#include <algorithm>
using namespace std;

#include <fstream>
#include <unordered_map>
#include <vector>

int main() {
  ifstream cin("measurement.in");
  ofstream cout("measurement.out");

  int n;
  cin >> n;

  using record = int[3];

  vector<record> r(n);
  for (auto &rec : r) {
    string cow;
    int a, b, c;
    cin >> rec[0] >> cow >> rec[2];
    rec[1] = cow[0] == 'E' ? 0 : cow[0] == 'B' ? 1 : 2;
  }

  sort(r.begin(), r.end());

  vector<int> h = {7, 7, 7};
  vector<int> f = {0, 1, 2};
  int cnt = 0;

  for (auto rec : r) {
    h[rec[1]] += rec[2];
    int mx = *max_element(h.begin(), h.end());
    vector<int> nf;
    for (int i = 0; i < 3; i++)
      if (h[i] == mx)
        nf.push_back(i);
    cnt += nf != f;
    f = std::move(nf);
  }

  cout << cnt << '\n';
}
