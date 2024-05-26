// https://ekzlib.netlify.app/view/suffix_array.cpp
// Eric K. Zhang +(modified with semenInRussia) 2017+2024

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> suffix_array(string s) {
  int n = s.size();
  vector<int> p(n), c(n);
  for (int i = 0; i < n; i++) {
    p[i] = n - 1 - i;
    c[i] = s[i];
  }
  stable_sort(p.begin(), p.end(), [&s](int i, int j) { return s[i] < s[j]; });
  for (int len = 1; len < n; len *= 2) {
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      bool same = i && p[i - 1] + len < n   //
                  && c[p[i]] == c[p[i - 1]] //
                  && c[p[i] + len / 2] == c[p[i - 1] + len / 2];
      c[p[i]] = same ? c[p[i - 1]] : i;
    }
    vector<int> cnt(n), pp(p);
    for (int i = 0; i < n; i++)
      cnt[i] = i;
    for (int i = 0; i < n; i++) {
      int s1 = pp[i] - len;
      if (s1 >= 0)
        p[cnt[c[s1]]++] = s1;
    }
  }
  return p;
}

int cmp(string &s, int ind, string &p) {
  int i = ind, j = 0;
  int n = (int)s.size(), m = (int)p.size();
  while (i < n && j < m && s[i] == p[j])
    i++, j++;
  if (j == m)
    return 0;
  return s[i] > p[j] ? +1 : -1;
}

int main() {
  string s = "acoolismyfovouriteyoutbuer#", p = "coo";
  vector<int> sa = suffix_array(s);

  int n = (int)s.size();
  int l = -1, r = n;
  while (r > l + 1) {
    int mid = (r + l) / 2;
    int c = cmp(s, sa[mid], p);
    if (c >= 0)
      r = mid;
    else
      l = mid;
  }
  int ind = sa[r];
  cout << s.substr(ind, p.size()) << '\n';

  cout << string(10, '=') << '\n';
  for (int i : sa)
    cout << s.substr(i) << '\n';

  return 0;
}
