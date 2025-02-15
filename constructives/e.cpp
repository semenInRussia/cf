// semenInRussia 2025
// [not solved]
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

vector<int> cur;
int s = 0;

const int A = 30;

void gen(int n) {
  if (int(cur.size()) == n + 1) {
    int d = cur.back() - cur[1];
    if (d * d == s) {
      for (int x : cur) {
        cout << x << " ";
      }
      cout << endl;
    }
    return;
  }

  for (int x = cur.back() + 1; x < A; x++) {
    cur.push_back(x);
    s += x;
    gen(n);
    s -= x;
    cur.pop_back();
  }
}

int main() {
  int n;
  cin >> n;

  cur.push_back(0);

  gen(n);
  cur.push_back(0);
}
