// Copyright 2024 semenInRussia
// CF https://codeforces.com/contest/1137/problem/D
// #graphs #floyd #interactive *2400

#include <iostream>
#include <vector>

using namespace std;

// return true, if all players after are located in the same point
int move(vector<int> players) {
  cout << "next";
  for (int p : players)
    cout << ' ' << p;
  cout << endl;
  cout.flush();

  int k;
  cin >> k;
  string _;
  for (int i = 0; i < k; i++)
    cin >> _;

  return k;
}

int move() {
  vector<int> p;
  for (int i = 0; i < 10; i++)
    p.push_back(i);
  return move(p);
}

int main() {
  // move 0 and 1
  bool stop = false;
  move({0, 1}), move({0, 1});
  move({1});

  while (move({1}) != 2)
    move({0, 1});
  while (move() != 1)
    ;

  cout << "done" << endl;
}
