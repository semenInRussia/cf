#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

const int maxn = 150;
unordered_set<string> props[maxn];

int count_general_props(int i, int j) {
  int cnt = 1;
  for (auto prop : props[i])
    cnt += props[j].count(prop);
  return cnt;
}

int main() {
  ifstream cin("guess.in");
  ofstream cout("guess.out");

  int n;
  cin >> n;

  for (int ani = 0; ani < n; ani++) {
    string name;
    int nprops;
    cin >> name >> nprops;
    for (int j = 0; j < nprops; j++) {
      string prop;
      cin >> prop;
      props[ani].insert(prop);
    }
  }

  int ans = -1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = max(ans, count_general_props(i, j));

  cout << ans;
}
