#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> intersection(unordered_set<int> &a, unordered_set<int> &b) {
  unordered_set<int> c = {};
  for (auto x : a)
    if (b.count(x))
      c.insert(x);
  return c;
}

int main() {
  ifstream cin("guess.in");
  ofstream cout("guess.out");

  int n;
  cin >> n;

  unordered_map<string, int> props_id;
  unordered_map<int, unordered_set<int>> props_animals;

  for (int ani = 0; ani < n; ani++) {
    string name;
    int nprops;
    cin >> name >> nprops;
    for (int j = 0; j < nprops; j++) {
      string prop;
      cin >> prop;
      if (!props_id.count(prop))
        props_id[prop] = props_id.size();
      int pid = props_id[prop];
      if (!props_animals.count(pid))
        props_animals[pid] = {};
      props_animals[pid].insert(ani);
    }
  }

  // take a property with the biggest amount of animals.
  // - if it's one, stop
  // remove animals without property from every prop
  // remove property
  // loop

  int ans = 0;
  while (1) {
    int mx_prop = props_animals.begin()->first;
    for (auto [prop, anis] : props_animals)
      if (props_animals[prop].size() > props_animals[mx_prop].size())
        mx_prop = prop;

    ans += props_animals[mx_prop].size() >= 1;

    if (props_animals[mx_prop].size() <= 1) {
      break;
    }

    auto cur_anis = props_animals[mx_prop];
    for (auto [prop, anis] : props_animals) {
      props_animals[prop] = intersection(props_animals[prop], cur_anis);
    }

    props_animals.erase(mx_prop);
  }

  cout << ans;
}
