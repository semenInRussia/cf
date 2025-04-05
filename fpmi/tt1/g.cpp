// semenInRussia 2025
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 205;
const int R = 6e3 + 10;
const int K = 60;
int n, t, f[N][R], res;
string s;

struct node {
  int fir, sec;
};

node pos[K][R];

vector<int> v[N][N];
void restore(node p) {
  if (p.sec == -1) {
    return;
  }
  restore(pos[p.sec][p.fir]);
  if (p.sec > 25) {
    cout << char(p.sec - 26 + 'A');
  } else {
    cout << char(p.sec + 'a');
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> t;
  for (int o = 1; o <= t; o++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int j = 0; j < 52; j++) {
        v[i][j].clear();
      }
      for (int j = 0; j < int(s.size()); j++) {
        if (s[j] >= 'A' && s[j] <= 'Z') {
          v[i][s[j] - 'A' + 26].push_back(j + 1);
        }
        if (s[j] >= 'a' && s[j] <= 'z') {
          v[i][s[j] - 'a'].push_back(j + 1);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < R; j++) {
        f[i][j] = 0;
      }
    }

    queue<node> q;
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < (1 << n); j++) {
        q.push({j, i});
        pos[i][j].fir = -1;
        pos[i][j].sec = -1;
      }
    }

    int x = -1, y = -1;
    while (!q.empty()) {
      auto [a, b] = q.front();
      q.pop();
      int fl = 1;
      for (int i = 1; i <= n; i++) {
        if (((a >> (i - 1)) & 1) >= v[i][b].size()) {
          fl = 0;
        }
      }
      if (!fl) {
        continue;
      }
      f[b][a] = max(f[b][a], 1);
      if (f[b][a] > res) {
        res = f[b][a];
        x = a;
        y = b;
      }

      for (int i = 0; i < K; i++) {
        bool check = true;
        int to = 0;
        for (int j = 1; j <= n; j++) {
          int tot = ((a >> (j - 1)) & 1);
          tot = v[j][b][tot];
          int k = 0;
          while (k < int(v[j][i].size()) && v[j][i][k] <= tot) {
            k++;
          }
          if (k >= int(v[j][i].size())) {
            check = false;
            break;
          }
          if (k == 1) {
            to |= (1 << (j - 1));
          }
        }
        if (!check) {
          continue;
        }
        if (f[i][to] < f[b][a] + 1) {
          f[i][to] = f[b][a] + 1;
          pos[i][to] = {a, b};
          q.push({to, i});
        }
      }
    }
    cout << res << "\n";
    restore({x, y});
    cout << "\n";
  }
}
