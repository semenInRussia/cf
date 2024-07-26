// semenInRussia 2024
// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/L
#include <iostream>
#include <unordered_set>
using namespace std;
const int N = 6e4 + 1;

// we have:
// a : {1, 2, 3, 4, ..., n}
// b : {2, 3, 4, 5, ..., n+1}

// find amount of b placements, that
// a[i] % b[i] == 0

unordered_set<int> b;
