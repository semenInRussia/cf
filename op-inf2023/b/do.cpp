// Copyright 2024 semenInRussia

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Diap {
  size_t l;
  size_t r;
};

vector<Diap> diaps_in(size_t l, size_t r, size_t k);
void print_diaps(vector<Diap> ds);

int main() {
  for (size_t k = 1; k < 20; k++) {
    for (size_t r = 0; r < 10; r++) {
      cout << k << " (" << 0 << "-" << r << "): ";
      auto diaps = diaps_in(0, r, k);
      print_diaps(diaps);
      cout << " :" << diaps.size() << endl;
    }
  }

  return 0;
}

void print_diaps(vector<Diap> ds) {
  for (auto diap : ds) {
    if (diap.r == diap.l) {
      cout << diap.r << ", ";
    } else {
      cout << diap.l << '-' << diap.r << ", ";
    }
  }
}

vector<Diap> diaps_in(size_t l, size_t r, size_t k) {
  vector<size_t> nums;

  for (size_t i = l; i <= r; i++) {
    nums.push_back(i ^ k);
  }

  sort(nums.begin(), nums.end());

  size_t deap_beg = nums[0];
  size_t prev = nums[0];

  vector<Diap> ds;

  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] != prev + 1) {
      ds.push_back({deap_beg, prev});
      deap_beg = nums[i];
    }

    prev = nums[i];
  }

  ds.push_back({deap_beg, prev});

  return ds;
}
