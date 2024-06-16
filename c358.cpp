#include <iostream>
#include <vector>

using namespace std;

string names[3] = {"Stack", "Queue", "Front"};
int cnt[3];

int main() {
  int n;
  cin >> n;

  int typ = 0;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;

    if (q == 0) {
      vector<string> ans = {};
      for (int j = 0; j < 3; j++)
        if (cnt[j])
          ans.push_back(names[j]), cnt[j]--;
      cout << ans.size();
      for (auto name : ans)
        cout << ' ' << "pop" << name;
      cout << endl;
    }

    if (q != 0) {
      int typ = 0;
      for (int j = 0; j < 3; j++)
        if (cnt[typ] > cnt[j])
          typ = j;
      cnt[typ]++;
      cout << "push" << names[typ] << endl;
    }
  }
}
