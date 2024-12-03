// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

const int N = 2005;
string t[N];
int a[N];
int cnt[360];

string bad[] = {"NW", "EN", "WS", "SE"};

int sign(char a, char b) {
  string ab;
  ab.resize(2);
  ab[0] = a;
  ab[1] = b;
  return count(bad, bad + 4, ab) ? -1 : +1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  for (int i = 0; i < n; i++) {
    char c, g;
    int v;
    sscanf(t[i].c_str(), "%c%d%c", &c, &v, &g);
    a[i] = 0;
    if (c == 'E') {
      a[i] += 90;
    } else if (c == 'S') {
      a[i] += 180;
    } else if (c == 'W') {
      a[i] += 270;
    }

    a[i] += sign(c, g) * v;
    a[i] %= 360;
    if (a[i] < 0) {
      a[i] += 360;
    }
    cnt[a[i]]++;
  }

  // { -count, angle, index }
  tuple<int, int, int> ans = {0, 0, 0};
  for (int i = 0; i < n; i++) {
    ans = min(ans, {-cnt[a[i]], a[i], i});
  }
  cout << get<2>(ans) + 1;
}
