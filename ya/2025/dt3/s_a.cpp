// semenInRussia 2025
// it's a file that stress testing your code, note that I consider your "smart
// solution" have a type a.cpp and the stupid _a.cpp. And this file must be
// s_a.cpp also this file generate tests

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

void check() {
  system("_a.exe < input.txt > output.txt");
  system("a.exe < input.txt > actual.txt");

  if (system("fc actual.txt output.txt")) {
    cout << "found!";
    exit(0);
  }
}

int main() {
  system("g++ a.cpp -o a.exe");
  system("g++ _a.cpp -o _a.exe");

  int n = 2;
  for (int i = 1; i < n; i++) {

    // gen tests
    ofstream input("input.txt");

    mt19937 mt(time(0));

    int n = 10;

    input << n << "\n";
    int MAX = 100;
    vector<pair<int, int>> p(n);

    vector<int> used(MAX);

    for (auto &x : p) {
      x.first = mt() % MAX;
      while (used[x.first]) {
        x.first++;
      }
      used[x.first] = true;
      x.second = mt() % MAX;
    }

    sort(p.begin(), p.end());
    for (auto [x, h] : p) {
      input << x << " " << h << "\n";
    }

    input.flush();

    check();
  }

  cout << "ok!";
}
