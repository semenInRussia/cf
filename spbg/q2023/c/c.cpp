// Copyright 2024 semenInRussia

#include <cinttypes>
#include <cstdio>
#include <cstring>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

size_t str_find(char *s, char *needle, size_t pos = 0) {
  for (size_t i = pos; s[i]; ++i) {
    for (size_t j = 0;; ++j) {
      if (!needle[j])
        return i;
      if (s[i + j] != needle[j])
        break;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);

  auto fp = stdin;

  // 2 * 10^6
  char str[2000000];
  char needle[2000000];

  fscanf(fp, "%s\n%s", str, needle);

  size_t n = strlen(str);
  size_t k = strlen(needle);

  size_t mult = k / n + 1;

  char o[2000000];
  memcpy(o, str, n);

  // 10^6 -> 2*10^8

  while (mult--) {
    strcat(str, o);
  }

  size_t counted = 0;
  size_t pos = str_find(str, needle, 0);

  while (pos < n) {
    counted++;
    pos = str_find(str, needle, pos + 1);
  }

  cout << counted << endl;

  return 0;
}
