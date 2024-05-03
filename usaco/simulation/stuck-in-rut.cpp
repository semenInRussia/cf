#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

struct Cow {
  int id, x, y;
  char dir;
};

int main() {
  int n;
  cin >> n;
  vector<Cow> cows(n);
  int t = 0;
  for (auto &cow : cows) {
    cin >> cow.dir >> cow.x >> cow.y;
    cow.id = t++;
  }

  using point = pair<int, int>;

  set<point> f;
  vector<int> eaten(n);

  const int maxround = 100'000;

  for (int round = 0; round < maxround; round++) {
    vector<point> toadd;
    for (auto &cow : cows) {
      if (cow.id == -1)
        continue;

      point p = {cow.x, cow.y};
      if (f.count(p)) {
        // a cell is busy
        cow.id = -1;
        continue;
      }

      eaten[cow.id]++;
      toadd.push_back(p);
      if (cow.dir == 'N')
        cow.y++;
      else
        cow.x++;
    }

    for (auto p : toadd)
      f.insert(p);
  }

  unordered_set<int> inf;
  for (auto cow : cows)
    if (cow.id != -1)
      inf.insert(cow.id);

  for (int i = 0; i < n; i++) {
    if (inf.count(i)) {
      cout << "Infinity\n";
    } else {
      cout << eaten[i] << endl;
    }
  }
}
