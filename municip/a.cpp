// semenInRussia 2024
using namespace std;
#include <cstdio>

int main() {
  int h, m;
  scanf("%d:%d", &h, &m);
    int h2, m2;
  scanf("%d:%d", &h2, &m2);
  
  int h3 = 24 - h + h2;
  int m3 = m2 - m;
  if (m3 < 0) {
    h3--;
    m3 += 60;
  }
  printf("%02d:%02d", h3, m3);
}
