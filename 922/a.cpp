#include <numeric>
using ull = unsigned long long;

#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t n;
  cin >> n;

  vector<int> a;
  auto d = accumulate(a.begin(), a.end(), 0);
  auto s = accumulate(a.begin(), a.end(), 0);
  cout << d + s << endl;

  return 0;
}
