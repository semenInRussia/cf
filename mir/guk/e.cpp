// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

string vchars = "D.U";
string hchars = "L.R";

void move(int ax, int ay, int bx, int by, bool fst) {
  int hdir = (ax > bx) ? -1 : +1;
  int vdir = (ay > by) ? -1 : +1;
  char vch = vchars[vdir + 1];
  char hch = hchars[hdir + 1];

  if (fst) {
    for (int i = 0; i < abs(ax - bx); i++)
      cout << hch;
    for (int i = 0; i < abs(ay - by); i++)
      cout << vch;
  } else {
    for (int i = 0; i < abs(ay - by); i++)
      cout << vch;
    for (int i = 0; i < abs(ax - bx); i++)
      cout << hch;
  }
}

void solve() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  // first: the straight way
  //   - move with xdir while x != tx (sx - tx times)
  //   - move with xdir while x != tx
  move(sx, sy, tx, ty, 0);
  if (sx != tx && sy != ty) {
    move(tx, ty, sx, sy, 0);
  } else if (sx == tx) {
    // now
    // s
    // .
    // t
    move(tx, ty, sx + 1, sy, 1);
    cout << 'L';
    // now
    // s.
    // ..
    // t.
    cout << 'L';
    move(sx - 1, sy, tx - 1, ty, 0);
    cout << 'R';
    // now
    // .s.
    // ...
    // .t.
    cout << "URR";
    //  ...
    // .s.
    // ...
    // .t.
    move(sx + 2, sy + 1, tx + 2, ty - 1, 0);
    //  ...
    // .s..
    // ....
    // .t..
    //    .
    // move(tx + 2, ty - 1, tx, ty, 1);
  } else if (sy == ty) {
    // now: s.......t
    move(tx, ty, sx, sy + 1, 0);
    cout << 'D';
    // now:
    // .........
    // s.......t
    cout << 'D';
    move(sx, sy - 1, tx, ty - 1, 0);
    cout << 'U';
    // now:
    // .........
    // s.......t
    // .........
    move(tx, ty, tx + 1, ty, 0);
    move(tx + 1, ty, tx + 1, sy - 2, 0);
    move(tx + 1, sy - 2, sx - 1, sy - 2, 0);
    move(sx - 1, sy - 2, sx, sy, 0);
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
