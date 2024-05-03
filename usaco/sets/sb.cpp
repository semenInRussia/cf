// Copyright 2018 Dhruv Rohatgi

#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 100000;
const int MAXB = 100000;

int N, B;
int depth[MAXN];
int did[MAXN];

bool dcmp(int a, int b) { return depth[a] < depth[b]; }

int snow[MAXB], dist[MAXB];
int ans[MAXB];
int bid[MAXB];

bool s_bcmp(int a, int b) { return snow[a] < snow[b]; }

int nxt[MAXN], pre[MAXN];

int main() {
  ifstream cin("snowboots.in");
  ofstream cout("snowboots.out");

  // read input
  cin >> N >> B;
  for (int i = 0; i < N; i++) {
    cin >> depth[i];
    did[i] = i;
  }
  for (int i = 0; i < B; i++) {
    cin >> snow[i] >> dist[i];
    bid[i] = i;
  }

  // sort snow fragments by depth
  sort(did, did + N, dcmp);

  // sort boots with their snow level
  sort(bid, bid + B, s_bcmp);

  // build a light linked list of snow fragments
  for (int i = 0; i < N; i++)
    nxt[i] = i + 1, pre[i] = i - 1;

  int j = N - 1;
  // we must find the step needed to go to Nth with boot snow level
  // NOTE: that if snow level > snow level2, then maxStep1 < maxStep2,
  // so cause we sort boots with snow level, maxStep will be increased
  // after every boot handle
  int maxStep = 1;
  for (int i = B - 1; i >= 0; i--) {
    int boot = bid[i];
    // for boot i find snow fragment j, what?
    while (j >= 0 && depth[did[j]] > snow[boot]) {
      int cur = did[j];
      // remove snow fragment from the "linked list"
      nxt[pre[cur]] = nxt[cur];
      pre[nxt[cur]] = pre[cur];

      // now the step needed
      maxStep = max(maxStep, nxt[cur] - pre[cur]);
      j--;
    }
    ans[boot] = maxStep <= dist[boot];
  }
  for (int i = 0; i < B; i++)
    cout << ans[i] << '\n';
}
