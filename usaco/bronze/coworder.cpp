// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using std::endl;
using std::string;
using std::vector;

const vector<string> COWS = []() {
  vector<string> tmp{"Bessie", "Buttercup", "Belinda", "Beatrice",
                     "Bella",  "Blue",      "Betsy",   "Sue"};
  // sort names lexicographically
  std::sort(std::begin(tmp), std::end(tmp));
  return tmp;
}();

int main() {
  std::map<string, int> cow_inds;
  for (int i = 0; i < COWS.size(); i++) {
    cow_inds[COWS[i]] = i;
  }

  std::ifstream read("lineup.in");
  int req_num;
  read >> req_num;
  vector<vector<int>> neighbors(COWS.size());
  for (int r = 0; r < req_num; r++) {
    string cow1, cow2, trash;
    read >> cow1 >> trash >> trash >> trash >> trash >> cow2;

    // Convert the names to their index in the list
    int c1 = cow_inds[cow1];
    int c2 = cow_inds[cow2];
    neighbors[c1].push_back(c2);
    neighbors[c2].push_back(c1);
  }

  vector<int> order;
  vector<bool> added(COWS.size());
  for (int c = 0; c < COWS.size(); c++) {
    if (!added[c] && neighbors[c].size() <= 1) {
      added[c] = true;
      order.push_back(c);

      if (neighbors[c].size() == 1) {
        int prev = c;
        int at = neighbors[c][0];
        while (neighbors[at].size() == 2) {
          added[at] = true;
          order.push_back(at);

          int a = neighbors[at][0];
          int b = neighbors[at][1];
          int temp_at = a == prev ? b : a;
          prev = at;
          at = temp_at;
        }
        added[at] = true;
        order.push_back(at);
      }
    }
  }

  std::ofstream out("lineup.out");
  for (int c : order) {
    out << COWS[c] << endl;
  }
}
