// semenInRussia 2024
// https://cses.fi/problemset/task/1083
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e5;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  cout << (unique(a, a + n) - a);
}
