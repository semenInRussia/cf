// semenInRussia 2024
// digital trie:
// - add number
// - remove number
// - by v: find max x^v for every number x
#include <cassert>
#include <iostream>
using namespace std;

int bit(int x, int j) { return (x >> j) & 1; }

const int L = 30;

struct bor {
  struct node {
    int len = 0;
    node *g[2];

    node() { g[0] = g[1] = 0; }
  };

  node t;

  int size() { return t.len; }
  bool empty() { return size() == 0; }

  bor() { t = node(); }

  void add(int x) {
    node *v = &t;
    for (int j = L - 1; j >= 0; j--) {
      v->len++;
      int c = bit(x, j);
      if (v->g[c] == 0) {
        v->g[c] = new node();
      }
      v = v->g[c];
    }
    v->len++;
  }

  void rem(int x) {
    node *v = &t;
    for (int j = L - 1; j >= 0; j--) {
      int c = bit(x, j);
      v->len--;
      v = v->g[c];
    }
    v->len--;
  }

  int find(int x) {
    if (empty()) {
      return 0;
    }

    node *v = &t;

    int ans = 0;

    for (int j = L - 1; j >= 0; j--) {
      int b = bit(x, j) ^ 1;
      if (v->g[b] == 0 || v->g[b]->len == 0) {
        b ^= 1;
      }

      v = v->g[b];

      assert(v != 0);
      ans ^= b << j;
    }

    return ans ^ x;
  }
};
