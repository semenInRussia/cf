// semenInRussia 2025
// it's a file that stress testing your code, note that I consider your "smart
// solution" have a type a.cpp and the stupid _a.cpp. And this file must be
// s_a.cpp also this file generate tests

#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

void check() {
  cerr << "check" << endl;
  system("_f2.exe < input.txt > output.txt");
  system("f.exe < input.txt > actual.txt");

  if (system("fc actual.txt output.txt")) {
    cout << "found!";
    exit(0);
  }
}

int main() {
  system("g++ f.cpp -o f.exe");
  system("g++ _f.cpp -o _f2.exe");

  int n = 5;

  while (1) {
    // gen tests
    ofstream input("input.txt");
    input << n << "\n";
    for (int i = 0; i < n; i++) {
      int x = rand() % 1000000;
      ++x;
      input << x << " ";
    }
    input.flush();
    check();
    cerr << "ok" << endl;
  }

  cout << "accepeted!";
}
