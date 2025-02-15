// semenInRussia 2025
// treap tree:
// 1. swapp(l, r): swap(a[l], a[l+1]), swap(a[l+2], a[l+3]), ...
// 2. sum(l, r): a[l] + a[l+1] + ... + a[r - 1]

#include <cassert>
#include <iostream>
#include <random>

using namespace std;

struct node {
  int x, y;
  int64_t sum;
  int sz = 1;
  node *lef = nullptr, *rig = nullptr;

  node(int v = 0) : x(v), y(rand()), sum(v) {}
};

int64_t sum(node *t) { return t == nullptr ? 0 : t->sum; }
int size(node *t) { return t == nullptr ? 0 : t->sz; }

// upd
void upd(node *t) {
  if (t == nullptr) {
    return;
  }

  t->sz = size(t->lef) + 1 + size(t->rig);
  t->sum = sum(t->lef) + t->x + sum(t->rig);
}

// split
pair<node *, node *> split(node *t, int k) {
  if (t == nullptr) {
    return {t, t};
  }

  if (k <= size(t->lef)) {
    auto [L, R] = split(t->lef, k);
    t->lef = R;
    upd(t);
    return {L, t};
  }

  auto [L, R] = split(t->rig, k - size(t->lef) - 1);
  t->rig = L;
  upd(t);
  return {t, R};
}

// merge
node *merge(node *a, node *b) {
  if (a == nullptr) {
    return b;
  }
  if (b == nullptr) {
    return a;
  }

  if (a->y > b->y) {
    a->rig = merge(a->rig, b);
    upd(a);
    return a;
  }

  b->lef = merge(a, b->lef);
  upd(b);
  return b;
}

// ctrlx
node *ctrlx(node *&t, int l, int r) {
  auto [L, X] = split(t, l);
  auto [Y, R] = split(X, r - l);
  t = merge(L, R);
  return Y;
}

// ctrlv
void ctrlv(node *&t, node *v, int i) {
  auto [L, R] = split(t, i);
  t = merge(merge(L, v), R);
}

const int N = 2e5 + 1000;
node heap[N];
int ptr = 0;

node *alloc_node(int x) {
  heap[ptr] = node(x);
  upd(&heap[ptr]);
  return &heap[ptr++];
}

struct swapper {
  node *odd = nullptr, *evn = nullptr;

  swapper(vector<int> &a) {
    for (int i = 0; i < int(a.size()); i++) {
      auto &s = (i & 1) ? odd : evn;
      s = merge(s, alloc_node(a[i]));
    }
  }

  void swapp(int l, int r) {
    // swap (l, l+1); (l+2, l+3); (l+4; l+5)
    // assert((r - l) % 2 == 0); //
    qry(1, l, r);
  }

  int64_t sum(int l, int r) { return qry(2, l, r); }

  int64_t qry(int typ, int l, int r) {
    int lo = l / 2;
    int ro = r / 2;
    int le = (l + 1) / 2;
    int re = (r + 1) / 2;

    auto to = ctrlx(odd, lo, ro);
    auto te = ctrlx(evn, le, re);

    if (typ == 1) {
      // swapping
      ctrlv(odd, te, lo);
      ctrlv(evn, to, le);
      return 0;
    } else {
      // sum
      auto ans = ::sum(to) + ::sum(te);
      ctrlv(odd, to, lo);
      ctrlv(evn, te, le);
      return ans;
    }
  }
};
