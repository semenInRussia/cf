// semenInRussia 2025
// it's a file that stress testing your code, note that I consider your "smart
// solution" have a type a.cpp and the stupid _a.cpp. And this file must be
// s_a.cpp also this file generate tests

#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

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

  int n = 6;
  int tt = 500;
  vector<int> p(n), k(n), s(n);
  while (tt--) {
    ofstream inp("input.txt");
    int K = rand() % 20;
    for (int i = 0; i < n; i++) {
      p[i] = rand() % n;
      k[i] = rand() % 20;
      s[i] = rand() % 20;
    }
    inp << n << " " << K << "\n";
    for (int i = 0; i < n; i++) {
      inp << p[i] << " ";
    }
    inp << "\n";
    for (int i = 0; i < n; i++) {
      inp << s[i] << " ";
    }
    inp << "\n";
    for (int i = 0; i < n; i++) {
      inp << k[i] << " ";
    }
    inp << "\n";
    inp.flush();
    check();
  }

  cout << "ok!";
}
