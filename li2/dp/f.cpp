// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
using lll = __int128;

const int N = 1000;
// o[i] is amount of sequences with length = i, ended with 1
// z[i] is amount of ... ended with 0
lll o[N], z[N];

char s[128];
void print(lll x) {
  int i = 0;
  while (x) {
    s[i++] = (x % 10) + '0';
    x /= 10;
  }
  reverse(s, s + i);
  s[i] = '\0';
  cout << s;
}

int main() {
  int n;
  cin >> n;
  o[1] = z[1] = 1; // for n=1
  for (int i = 2; i <= n; i++) {
    o[i] = z[i - 1];
    z[i] = z[i - 1] + o[i - 1];
  }
  print(o[n] + z[n]);
}
