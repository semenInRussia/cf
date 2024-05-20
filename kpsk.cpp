// Copyright 2024 semenInRussia
// using namespace std;

const int maxn = 15;
int d[maxn][maxn];
int main() {
  int w[] = {5, 3, 5}, n = sizeof(w) / sizeof(int);
  d[0][0] = 1;
  for (int x = 0; x < maxn; x++)
    for (int k = 0; k < n; k++)
      d[x][k + 1] = d[x][k] | (x >= w[k] && d[x - w[k]][k]);
}
