// Copyright 2024 semenInRussia
#include <bitset>
using namespace std;

const int maxn = 20;
bitset<maxn> possible;
int main() {
  int w[] = {1, 3, 5, 5}, n = size(w);
  possible[0] = true;
  for (int k = 0; k < n; k++)
    possible |= possible << w[k];
}
