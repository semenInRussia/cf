// Copyright 2024 semenInRussia

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> t(n);

  for (auto &s : t) {
    // С:ММ:ЧЧ ДД.ММ.ГГГГ
    int sec, minute, hour, date, mount, year;
    scanf("%d:%d:%d %d.%d.%d", &sec, &minute, &hour, &date, &mount, &year);
    char buf[100];
    sprintf(buf, "%04d:%04d:%04d %04d.%04d.%04d", year, mount, date, hour,
            minute, sec);
    s = buf;
  }

  sort(t.begin(), t.end());

  for (auto s : t) {
    int sec, minute, hour, date, mount, year;
    sscanf(s.c_str(), "%04d:%04d:%04d %04d.%04d.%04d", &year, &mount, &date,
           &hour, &minute, &sec);
    printf("%02d:%02d:%02d %02d.%02d.%04d\n", sec, minute, hour, date, mount,
           year);
  }

  return 0;
}
