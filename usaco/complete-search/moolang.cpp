#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string take(vector<string> &arr) {
  string wrd = arr.back();
  arr.pop_back();
  return wrd;
}

vector<string> nouns, conjs, verbs, iverbs;

struct paragraph {
  int _used, t1, t2, ot1, ot2, onouns;

  string build() {
    vector<string> tnouns = nouns, tconjs = conjs, tverbs = verbs,
                   tiverbs = iverbs;
    int tot1 = ot1, tot2 = ot2;
    // --
    string text = "";
    // build type1
    for (int i = 0; i < t1; i++) {
      text += i ? " " : "";
      text += take(nouns) + " " + take(iverbs);
      if (ot1 || ot2) {
        text += " " + take(conjs) + " ";
        if (ot1--) {
          text += take(nouns) + " " + take(iverbs);
        } else if (ot2--) {
          text += take(nouns) + " " + take(verbs) + " " + take(nouns);
        }
      }
    }

    // build type2
    for (int i = 0; i < t2; i++) {
      text += i ? " " : "";
      text += take(nouns) + " " + take(verbs) + take(nouns);
      if (!i)
        for (int j = 0; j < onouns; j++)
          text += ", " + take(nouns);
      if (ot1 || ot2) {
        text += " " + take(conjs) + " ";
        if (ot1--) {
          text += take(nouns) + " " + take(iverbs);
        } else if (ot2--) {
          text += take(nouns) + " " + take(verbs) + " " + take(nouns);
        }
      }
    }

    // defer
    nouns = tnouns, conjs = tconjs, verbs = tverbs, tiverbs = iverbs;
    ot1 = tot1, ot2 = tot2;

    return text;
  }
};

void solve() {
  int n, c, p;
  cin >> n >> c >> p;

  string btxt = "";
  int bst = 0;
}

int main() {
  freopen("moo.in", "r", stdin);

  int t;
  cin >> t;
  while (t--)
    solve();
}
