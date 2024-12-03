// semenInRussia 2024
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

string s;

#define isz(x) int(x.size())

int main() {
  getline(cin, s);
  int n;
  cin >> n;

  // ans[i][j] => ans[j][i]
  for (int i = 0; i < n; i++) {
    // print every nthth symbol
    for (int j = i; j < isz(s); j += n) {
      cout << s[j];
    }
    cout << "\n";
  }
}
