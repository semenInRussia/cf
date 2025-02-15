// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct card {
  string col, x;
};

istream &operator>>(istream &in, card &c) { return in >> c.col >> c.x; }

bool operator<(card a, card b) {
  return (a.col < b.col) || (a.col == b.col && a.x < b.x);
}

bool operator==(card a, card b) { return a.col == b.col && a.x == b.x; }
bool operator!=(card a, card b) { return !(a == b); }

void solve() {
  int n, a, q;
  cin >> n >> a >> q;

  card c0;
  cin >> c0;

  vector<set<card>> hand(n);
  vector<int> leave;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a; j++) {
      card c;
      cin >> c;
      hand[i].insert(c);
    }
  }

  int x = 0;
  int who = 1;

  int t = 1;

  while (q--) {
    string typ;
    cin >> typ;

    if (typ == "->") {
      card c;
      cin >> c;

      bool uno = false;

      string v;
      cin >> v;
      if (v == "AND") {
        cin >> v; // uno
        uno = true;
      }

      int j;
      cin >> j;
      j--;

      if (!hand[j].count(c)) {
        cout << "no such card BY player " << j << " ON turn " << t << "\n";
        return;
      }

      if (j != who && c != c0) {
        cout << "other player's turn BY player " << j << " ON turn " << t
             << "\n";
        return;
      }

      // wrong

      if (c.col != c0.col && c.x != c0.x) {
        cout << "non-matching card BY player " << j << " ON turn " << t << "\n";
        return;
      }

      hand[j].erase(hand[j].find(c));

      if ((hand[j].size() == 1 && !uno) || (hand[j].size() != 1 && uno)) {
        cout << "failed 'Uno! BY player " << j << " ON turn " << t << "\n";
        return;
      }

      if ()
    }
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
