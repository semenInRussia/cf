// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 100;
int a[N], b[N], c[N];

int main() {
  int n;
  cin >> n;
  b[0] = 1;
  a[1] = b[1] = c[1] = 1;
  for (int i = 2; i <= n; i++) {
    int sm = a[i - 1] + b[i - 1] + c[i - 1];
    a[i] = c[i] = sm;
    b[i] = c[i - 1] + b[i - 1];
  }
  cout << a[n] + b[n] + c[n];
}
