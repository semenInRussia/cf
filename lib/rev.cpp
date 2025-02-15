// semenInRussia 2025
// Treap tree with implicit key:
//
// 1. reverse elements on [l, r)
// 2. get minimum on [l, r)

#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int inf = 1e9 + 100;

struct node {
  int x;
  int y;
  int mn;
  int sz = 1; // size of subtree
  bool lazy = false;
  node *lef = nullptr, *rig = nullptr;

  node(int _v = 0) : x(_v), y(rand()) {}
};

int size(node *t) { return t == nullptr ? 0 : t->sz; }

int mn(node *t) { return t == nullptr ? inf : t->mn; }

void apply(node *t) {
  if (t == nullptr) {
    return;
  }

  t->lazy ^= 1;

  swap(t->lef, t->rig);

  return;
}

void push(node *t) {
  if (t->lazy) {
    apply(t->lef);
    apply(t->rig);
    t->lazy = false;
  }
}

node *upd(node *t) {
  if (t == nullptr) {
    return t;
  }

  t->sz = size(t->lef) + 1 + size(t->rig);
  t->mn = min(mn(t->lef), min(t->x, mn(t->rig)));

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
    push(a);
    a->rig = merge(a->rig, b);
    return upd(a);
  } else {
    push(b);
    b->lef = merge(a, b->lef);
    return upd(b);
  }
}

pair<node *, node *> split(node *t, int k) {
  if (t == nullptr) {
    return {nullptr, nullptr};
  }

  push(t);

  if (k > size(t->lef)) {
    auto [L, R] = split(t->rig, k - size(t->lef) - 1);
    t->rig = L;
    return {upd(t), R};
  }

  auto [L, R] = split(t->lef, k);
  t->lef = R;
  return {L, upd(t)};
}

const int N = 1e5 + 100;
node heap[N];
int ptr = 0;

node *alloc_node(int j) {
  heap[ptr] = node(j);
  upd(&heap[ptr]);
  return &heap[ptr++];
}

vector<int> ans;

int main() {
  int n, m;
  cin >> n >> m;

  node *root = nullptr;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    root = merge(root, alloc_node(x));
  }

  while (m--) {
    int typ, l, r;
    cin >> typ >> l >> r;
    l--;

    auto [L, X] = split(root, l);
    auto [Y, R] = split(X, r - l);

    if (typ == 1) {
      // reverse
      apply(Y);
    } else {
      // get min
      cout << mn(Y) << "\n";
    }

    root = merge(L, merge(Y, R));
  }
}
