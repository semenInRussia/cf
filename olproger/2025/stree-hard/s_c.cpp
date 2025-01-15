// semenInRussia 2025
#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

void check() {
  system("_c.exe < input.txt > actual.txt");
  system("c.exe < input.txt > output.txt");

  if (system("fc actual.txt output.txt")) {
    cout << "found!";
    exit(0);
  }
}

int main() {
  system("g++ c.cpp -o c.exe");
  system("g++ _c.cpp -o _c.exe");

  int n = 100;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // gen tests
      ofstream input("input.txt");
      input << i << " " << j << endl;
      input.flush();

      check();
    }
  }

  cout << "ok!";
}
