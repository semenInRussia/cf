// semenInRussia 2024
// Disjoin System Union (DSU), very usable thing
#include <iostream>
using namespace std;

const int N = 1e6;
int p[N];
int64_t a[N];

int get(int i) {
  if (p[i] == i) {
    return i;
  }
  return p[i] = get(p[i]);
}

int join(int a, int b) {
  b = get(b);
  a = get(a);
  return p[b] = a;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
}
