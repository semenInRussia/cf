// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

int a[5];

int main() {
  string who;
  cin >> who;

  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  auto j = min_element(a, a + 5) - a;

  if (who == "Masha") {
    a[j]--;
  } else {
    // assert(who=="Valya")
    a[j]++;
  }

  for (int i = 0; i < 5; i++) {
    cout << a[i] << " ";
  }
}
