// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;
const int N = 100172, G = 316;
ll add[N], assign[N] = {-1};
ll sm[N], a[N];

int group(int i) { return i / G; }
void recompute(int g) {
  int l = g * G, r = (g + 1) * G;
  if (assign[g] != -1) {
    for (int i = l; i < r; i++)
      a[i] = assign[g];
    assign[g] = -1;
  }
  if (add[g]) {
    for (int i = l; i < r; i++)
      a[i] += add[g];
    add[g] = 0;
  }
  sm[g] = 0;
  for (int i = l; i < r; i++)
    sm[g] += a[i];
}

ll qry(int l, int r) {
  int gl = group(l), gr = group(r);
  ll ans = 0;
  recompute(gl);
  if (gl == gr) {
    for (int i = l; i < r; i++)
      ans += a[i];
    return ans;
  }
  for (int i = l; i < (gl + 1) * G; i++)
    ans += a[i];
  recompute(gr);
  for (int i = gr * G; i < r; i++)
    ans += a[i];
  for (int g = gl + 1; g < gr; g++)
    ans += sm[g];
  return ans;
}

void inc(int l, int r, ll v) {
  int gl = group(l), gr = group(r);
  //
  recompute(gl);
  if (gl == gr) {
    for (int i = l; i < r; i++) {
      a[i] += v;
      sm[gl] += v;
    }
    return;
  }

  for (int i = l; i < (gl + 1) * G; i++) {
    a[i] += v;
    sm[gl] += v;
  }
  for (int g = gl + 1; g < gr; g++) {
    add[g] += v;
    sm[g] += v * G;
  }
  recompute(gr);
  for (int i = gr * G; i < r; i++) {
    a[i] += v;
    sm[gr] += v;
  }
}

void change(int l, int r, ll v) {
  int gl = group(l), gr = group(r);
  //
  recompute(gl);
  if (gl == gr) {
    for (int i = l; i < r; i++) {
      sm[gl] += v - a[i];
      a[i] = v;
    }
    return;
  }

  for (int i = l; i < (gl + 1) * G; i++) {
    sm[gl] += v - a[i];
    a[i] = v;
  }
  for (int g = gl + 1; g < gr; g++) {
    assign[g] = v;
    add[g] = 0;
    sm[g] = v * G;
  }
  recompute(gr);
  for (int i = gr * G; i < r; i++) {
    sm[gr] += v - a[i];
    a[i] = v;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      change(l, r, ll(v));
    } else if (typ == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      inc(l, r, ll(v));
    } else {
      int l, r;
      cin >> l >> r;
      cout << qry(l, r) << '\n';
    }
  }
}
