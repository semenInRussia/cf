// semenInRussia 2025
// it's a file that stress testing your code, note that I consider your "smart
// solution" have a type a.cpp and the stupid _a.cpp. And this file must be
// s_a.cpp also this file generate tests

#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

void check() {
  system("_c.exe < input.txt > output.txt");
  system("c.exe < input.txt > actual.txt");

  if (system("fc actual.txt output.txt")) {
    cout << "found!";
    exit(0);
  }
}

int main() {

  system("g++ c.cpp -o c.exe");
  system("g++ _c.cpp -o _c.exe");

  mt19937 mt(time(0));

  int n = 100;
  for (int i = 0; i < n; i++) {
    // gen tests
    ofstream input("input.txt");

    int n = 100;
    int k = mt() % n + 1;

    input << n << " " << k << "\n";

    const int MAX = 100;

    for (int i = 0; i < n; i++) {
      int a = mt() % MAX;
      int b = mt() % MAX;
      int c = 0;
      input << a << " " << b << " " << c << "\n";
    }

    input.flush();

    check();
  }

  cout << "ok!";
}
