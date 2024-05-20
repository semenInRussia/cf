// semenInRussia 2024
#include <iostream>
using namespace std;

const int maxn = 7;
int p[maxn] = {0, 6, 5, 4, 4, 0, 5};

int leader(int v) { return (p[v] == v) ? v : p[v] = leader(p[v]); }

void unite(int a, int b) {
  a = leader(a), b = leader(b);
  p[a] = b;
}

int main() {
  for (int i = 0; i < maxn; i++)
    cout << p[i] << ' ';
  cout << '\n';
  leader(1);
  for (int i = 0; i < maxn; i++)
    cout << p[i] << ' ';
}
