using namespace std;

#include <algorithm>
#include <fstream>

struct Segment {
  int ramp, l, r; // ramp is 1, when this is a ramp
};

void negative(Segment &s) {
  if (s.ramp)
    s.l *= -1, s.r *= -1;
}

Segment segs[int(2e3)];
int n;

int main() {
  ifstream cin("traffic.in");
  ofstream cout("traffic.out");
  cin >> n;

  for (int i = 0; i < n; i++) {
    string typ;
    cin >> typ >> segs[i].l >> segs[i].r;
    segs[i].ramp = typ != "none";
    if (typ == "off") negative(segs[i]);
  }

  // ensure that interval was between 0 and 5000, add fictive none sensor
  segs[n] = {false, 0, 5000};

  for (int rev = 0; rev < 2; rev++) {
    reverse(segs, segs + n);
    for (int i = 0; i < n; i++)
      negative(segs[i]);

    // Max possible interval
    int l = 0, r = 5000;

    for (int i = 0; i <= n; i++) {
      Segment s = segs[i];
      if (s.ramp) {
        int mn = min(s.l, s.r);
        int mx = max(s.l, s.r);
        l += mn, r += mx;
      } else {
        // intersection of current sensor and previous measures
        l = max(s.l, l), r = min(s.r, r);
      }
    }
    cout << l << ' ' << r << '\n';
  }
}
