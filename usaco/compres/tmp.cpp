// Copyright 2024 semenInRussia

#include <iostream>
#include <set>

using namespace std;

#define dist(s, x) distance(s.begin(), s.find(x))

int main() {
  set<int> xs = {1, 2, 3, 4, 7};
  cout << "7: " << (dist(xs, 7)) << endl;
  cout << "100: " << (dist(xs, 100)) << endl;
  cout << "3: " << (dist(xs, 3)) << endl;
  cout << "4: " << (dist(xs, 4)) << endl;
  cout << "7: " << (dist(xs, 7)) << endl;
}
