using namespace std;

#include <fstream>
#include <vector>

const int MAXN = 100;
vector<int> places[MAXN];

bool better(vector<int> &a, vector<int> &b) {
  bool ok = true;
  for (int i = 0; i < (int)a.size(); i++)
    ok &= a[i] > b[i];
  return ok;
}

int main() {
  ifstream cin("gymnastics.in");
  ofstream cout("gymnastics.out");

  int k, n;
  cin >> k >> n;

  for (int i = 0; i < k; i++) {
    for (int plc = 0; plc < n; plc++) {
      int cowi;
      cin >> cowi;
      places[cowi - 1].push_back(plc);
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      cnt += better(places[i], places[j]) || better(places[j], places[i]);

  cout << cnt << '\n';
}
