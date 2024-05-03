// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

using pii = pair<int, int>;
const int maxn = 1e5;

int mxgap = 1;
int f[maxn], d[maxn], s[maxn];
int boots[maxn], frags[maxn];
int answ[maxn];
set<int> line;

void mark(int i) { // mark i-th tile as not OK
  auto it = line.find(i);
  int prv = *prev(it), nxt = *next(it);
  mxgap = max(mxgap, nxt - prv);
  line.erase(it);
}

bool by_f(int a, int b) { return f[a] < f[b]; }
bool by_s(int a, int b) { return s[a] < s[b]; }

int main() {
  ifstream cin("snowboots.in");
  ofstream cout("snowboots.out");

  int n, b;
  cin >> n >> b;

  for (int i = 0; i < n; i++) {
    cin >> f[i];
    line.insert(i), frags[i] = i;
  }
  for (int i = 0; i < b; i++) {
    cin >> s[i] >> d[i];
    boots[i] = i;
  }

  // sort boots by s[i] by descending order, sort snow fragments with
  // f[i] desc
  sort(frags, frags + n, by_f), reverse(frags, frags + n);
  sort(boots, boots + b, by_s), reverse(boots, boots + b);

  // for every boot mark snow fragments and compare gap size with
  // d[boot]
  // a index in frags of the first frag that can be reached with boot
  int j = 0;
  for (int i = 0; i < b; i++) {
    int boot = boots[i];
    while (j < n && s[boot] < f[frags[j]])
      mark(frags[j]), j++;
    answ[boot] = mxgap <= d[boot];
  }

  for (int i = 0; i < b; i++)
    cout << answ[i] << '\n';
}
