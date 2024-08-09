// semenInRussia 2024
// https://cses.fi/problemset/task/1071
#include <iostream>
using namespace std;
using ll = long long;

// observations:
//
// 1. odd lines starts at the [0, i]
// 2. even lines starts at the [i, 0]
// 3. every line(i) is sum is (i * 2 + 1)
// 4. every line width is (i+1), it covers columns [0; i+1]
// 5. so if input is [y, x], we have 2 cases
//    a. if x <= y + 1
//         answer is their sum sum(2i+1)+1+x, if even
//         otherwise           sum(2i+1)+(2i+1)-x-1
//         or
//    b. if x > y + 1
//       we also must skip rows + (i+1-x), and take sum(i) + i+2
// 6. line i begins at the sum(2i+1) + 1

ll b(int i) { // return sum of 2*j + 1, for every j < i
  if (i == 0 || i == 1)
    return i;
  ll ans = 1ll * (0 + i - 1) * i / 2;
  return ans * 2 + i;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int y, x;
    cin >> y >> x;
    y--, x--;
    int i, j;
    if (x <= y)
      i = y, j = x;
    else
      i = x, j = i + (i - y);
    ll ans = b(i);
    if (i & 1)
      ans += 2 * i - j + 1;
    else
      ans += j + 1;
    cout << ans << '\n';
  }
}
