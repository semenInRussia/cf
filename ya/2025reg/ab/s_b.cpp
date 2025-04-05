// semenInRussia 2025
// it's a file that stress testing your code, note that I consider your "smart
// solution" have a type a.cpp and the stupid _a.cpp. And this file must be
// s_a.cpp also this file generate tests

#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

void check() {
  system("_b.exe < input.txt > output.txt");
  system("b.exe < input.txt > actual.txt");

  if (system("fc actual.txt output.txt")) {
    cout << "found!";
    exit(0);
  }
}

int main() {
  system("g++ b.cpp -o b.exe");
  system("g++ _b.cpp -o _b.exe");

  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 50; j++) {
      // gen tests
      ofstream input("input.txt");
      input << j << " " << i << endl;
      input.flush();

      check();
    }
  }

  cout << "ok!";
}
