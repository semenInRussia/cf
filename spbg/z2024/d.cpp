// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct node {
  int x;
  int y;
  int sz = 1; // size of subtree

  int64_t whole, nolef, norig, nolefrig;

  node *lef = nullptr, *rig = nullptr;

  node(int v = 0) : x(v), y(rand()), sz(1) {}
};

int size(node *t) { return t == nullptr ? 0 : t->sz; }
int64_t whole(node *t) { return t == nullptr ? 0 : t->whole; }
int64_t nolef(node *t) { return t == nullptr ? 0 : t->nolef; }
int64_t norig(node *t) { return t == nullptr ? 0 : t->norig; }
int64_t nolefrig(node *t) { return t == nullptr ? 0 : t->nolefrig; }

node *upd(node *t) {
  if (t == nullptr) {
    return t;
  }

  t->sz = size(t->lef) + 1 + size(t->rig);

  if (t->sz == 1) {
    t->whole = t->x;
    t->nolef = t->norig = t->nolefrig = 0;
  }

  if (t->lef != nullptr && t->rig != nullptr) {
    t->nolef = max(nolef(t->lef) + whole(t->rig),
                   nolefrig(t->lef) + t->x + nolef(t->rig));
    t->norig = max(whole(t->lef) + norig(t->rig),
                   norig(t->lef) + t->x + nolefrig(t->rig));
    t->nolefrig = max(nolef(t->lef) + norig(t->rig),
                      nolefrig(t->lef) + t->x + nolefrig(t->rig));
  } else if (t->rig != nullptr) {
    t->nolef = whole(t->rig);
    t->norig = max(t->x + nolefrig(t->rig), norig(t->rig));
    t->nolefrig = norig(t->rig);
  } else if (t->lef != nullptr) {
    t->norig = whole(t->lef);
    t->nolef = max(nolef(t->lef), nolefrig(t->lef) + t->x);
    t->nolefrig = nolef(t->lef);
  }

  if (t->sz > 1) {
    t->whole = max(whole(t->lef) + whole(t->rig),
                   norig(t->lef) + t->x + nolef(t->rig));
  }

  return t;
}

node *merge(node *a, node *b) {
  if (a == nullptr) {
    return b;
  }

  if (b == nullptr) {
    return a;
  }

  if (a->y > b->y) {
    a->rig = merge(a->rig, b);
    return upd(a);
  } else {
    b->lef = merge(a, b->lef);
    return upd(b);
  }
}

pair<node *, node *> split(node *t, int k) {
  if (t == nullptr) {
    return {nullptr, nullptr};
  }

  if (k > size(t->lef)) {
    auto [L, R] = split(t->rig, k - size(t->lef) - 1);
    t->rig = L;
    return {upd(t), R};
  }

  auto [L, R] = split(t->lef, k);
  t->lef = R;
  return {L, upd(t)};
}

const int N = 4e5;
int ptr = 0;
node heap[N];

node *alloc_node(int j) {
  heap[ptr] = node(j);
  upd(&heap[ptr]);
  return &heap[ptr++];
}

vector<int> ans;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  node *t = nullptr;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t = merge(t, alloc_node(x));
  }

  cout << whole(t) << "\n";

  string at;

  while (m--) {
    string typ;
    cin >> typ;
    if (typ == "insert") {
      int v, j;
      cin >> v >> at >> j;
      auto [L, R] = split(t, j);
      t = merge(L, merge(alloc_node(v), R));
    } else if (typ == "assign") {
      int v, j;
      cin >> v >> at >> j;
      auto [L, X] = split(t, j);
      auto [Y, R] = split(X, 1);
      t = merge(L, merge(alloc_node(v), R));
    } else {
      int j;
      cin >> at >> j;
      auto [L, X] = split(t, j);
      auto [Y, R] = split(X, 1);
      t = merge(L, R);
    }

    cout << whole(t) << "\n";
  }
}
