// Copyright 2023 chatGPT-3.5

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
  vector<int> max_tree, min_tree;
  vector<int> arr;
  int n;

  SegmentTree(vector<int> &a) {
    n = a.size();
    arr = a;
    max_tree.assign(4 * n, 0);
    min_tree.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  void build(int node, int start, int end) {
    if (start == end) {
      max_tree[node] = arr[start];
      min_tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      build(2 * node, start, mid);
      build(2 * node + 1, mid + 1, end);
      max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
      min_tree[node] = min(min_tree[2 * node], min_tree[2 * node + 1]);
    }
  }

  int query(int node, int start, int end, int left, int right) {
    if (right < start || left > end)
      return 0;
    if (left <= start && right >= end)
      return max_tree[node] - min_tree[node];
    int mid = (start + end) / 2;
    int left_query = query(2 * node, start, mid, left, right);
    int right_query = query(2 * node + 1, mid + 1, end, left, right);
    return max(left_query, right_query);
  }

  void update(int node, int start, int end, int index, int value) {
    if (start == end) {
      arr[index] = value;
      max_tree[node] = value;
      min_tree[node] = value;
    } else {
      int mid = (start + end) / 2;
      if (index <= mid)
        update(2 * node, start, mid, index, value);
      else
        update(2 * node + 1, mid + 1, end, index, value);
      max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
      min_tree[node] = min(min_tree[2 * node], min_tree[2 * node + 1]);
    }
  }
};

int main() {
  int k;
  cin >> k;

  vector<int> an(100000);
  for (int i = 1; i <= 100000; ++i) {
    an[i - 1] = (i * i % 12345 + i * i * i % 23456);
  }

  SegmentTree seg_tree(an);

  while (k--) {
    int xi, yi;
    cin >> xi >> yi;
    if (xi > 0) {
      int variation = seg_tree.query(1, 0, an.size() - 1, xi - 1, yi - 1);
      cout << variation << "\n";
    } else {
      seg_tree.update(1, 0, an.size() - 1, -xi - 1, yi);
    }
  }

  return 0;
}
