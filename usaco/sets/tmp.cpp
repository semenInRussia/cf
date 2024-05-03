#include <cmath>
#include <codecvt>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  std::pair<int, int> a = {1, 2};
  std::pair<int, int> b = {1, 0};
  cout << "< " << (a < b) << '\n';
  cout << "> " << (a > b) << '\n';
}
