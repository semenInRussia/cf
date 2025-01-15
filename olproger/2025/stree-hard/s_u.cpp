// semenInRussia 2025
// it's a file that stress testing your code, not that I consider your "smart
// solution" have a type a.cpp and the stupid _a.cpp. And this file must be
// s_a.cpp also this file generate tests

#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

void check() {
  system("_u.exe < input.txt > output.txt");
  system("u.exe < input.txt > actual.txt");

  if (system("fc actual.txt output.txt")) {
    cout << "found!";
    exit(0);
  }
}

int main() {
  system("g++ u.cpp -o u.exe");
  system("g++ _u.cpp -o _u.exe");

  for (int a = -10; a < 100; a++) {
    for (int j = 0; j < 100000; j++) {
      // gen tests
      ofstream input("input.txt");
      input << a << " " << j << endl;
      input.flush();

      check();
    }
  }

  cout << "ok!";
}
