// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

size_t n = 14;

vector<string> combs(size_t x);
vector<string> combs(size_t x, vector<unsigned> &ms, size_t mn);

vector<unsigned> composite_terms(size_t x);

int main() {
  for (auto comb : combs(n)) {
    cout << comb << endl;
  }

  return 0;
}

inline vector<string> combs(size_t x) {
  auto ms = composite_terms(x);
  return combs(x, ms, 0);
}

vector<string> combs(size_t x, vector<unsigned> &ms, size_t mn) {
  if (x == 0) {
    return {""};
  }

  vector<string> cs;

  for (auto m : ms) {
    if (m > x) {
      break;
    }

    if (m < mn) {
      continue;
    }

    for (string c : combs(x - m, ms, m)) {
      string el = to_string(m);

      if (c.size()) {
        el += "+" + c;
      }

      cs.push_back(el);
    }
  }

  return cs;
}

vector<unsigned> composite_terms(size_t x) {
  unordered_set<unsigned> nums = {1};

  for (size_t a = 2; a < x; a++) {
    for (size_t b = a; b < x; b++) {
      if (a * b <= x) {
        nums.insert(a * b);
      } else {
        b = x + 1;
      }
    }
  }

  vector<unsigned> result;

  for (auto x : nums) {
    result.push_back(x);
  }

  sort(result.begin(), result.end());

  return result;
}
