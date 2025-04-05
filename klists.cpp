// semenInRussia 2025
// https://leetcode.com/problems/merge-k-sorted-lists/
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#ifdef home
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    min_heap<pair<int, ListNode *>> q;
    for (auto it : lists) {
      if (it != nullptr) {
        q.push({it->val, it});
      }
    }

    ListNode *ans = new ListNode();
    ListNode *back = ans;

    while (!q.empty()) {
      auto [x, it] = q.top();
      q.pop();
      if (it->next != nullptr) {
        q.push({it->next->val, it->next});
      }
      back->next = it;
      back = back->next;
      back->next = nullptr;
    }

    return ans->next;
  }
};
