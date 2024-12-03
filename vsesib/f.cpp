// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;

string s;

struct substr {
  int l, r;
  bool empty = 0;

  substr(int _l, int _r, int _e) : l(_l), r(_r), empty(_e) {}
  substr() {}
  int size() { return r - l; }

  string str() {
    if (empty) {
      return "";
    }
    return s.substr(l, r - l);
  }
};

const substr none = {0, 0, 1};

bool operator<(substr a, substr b) { return a.str() < b.str(); }

const int N = 1e4;
pair<int, substr> f[N]; // f[i] - {-max amount divisions, min last substring}
bool stop[N];

const int inf = 1e9 + 5;

int main() {
  int n;
  cin >> n >> s;
  f[0] = {0, none};

  for (int i = 1; i <= n; i++) {
    f[i] = {+inf, none};
  }

  for (int i = 0; i < n; i++) {
    f[i + 1] = {-1, {0, i + 1, 0}};
    for (int j = 1; j <= i; j++) {
      auto str = substr(j, i + 1, 0);
      if (f[j].second < str) {
        auto op = f[j];
        op.first--;
        op.second = str;
        f[i + 1] = min(f[i + 1], op);
      }
    }
  }

  cout << -f[n].first << "\n";

  int v = n;
  while (v > 0) {
    stop[v] = 1;
    v -= f[v].second.size() + 1;
  }
  bool prv = 1;
  for (int i = 0; i < n; i++) {
    if (prv) {
      cout << char(toupper(s[i]));
      prv = 0;
    } else {
      cout << s[i];
      prv = 0;
    }
    if (stop[i]) {
      prv = 1;
      cout << "\n";
    }
  }
}
