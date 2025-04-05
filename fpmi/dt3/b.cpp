// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int x;
bool prv = 0;
int k = 0;

bool ask(int y) {
#ifdef home
  if (y == x) {
    exit(0);
  }
  bool r = rand() % 2 == 0;
#else
  cout << (y + 1) << endl;
  char c;
  cin >> c;
  if (c == 'E') {
    exit(0);
  }
  return c == 'G';
#endif
}

int n;

void solve() {
  int l = -1;
  int r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (ask(m)) {
      l = m;
    } else {
      r = m;
    }
  }
}

int main() {
  cin >> n;
  x = (rand() % n) + 1;
  while (1) {
    ask(n - 1);
    n--;
    solve();
  }
}
