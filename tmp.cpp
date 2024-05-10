void solve() {
  // Global Variables
  int n, m, k, d, x, y;
  string str;
  //------------------------------RISHU------------------------------//
  ci n;
  ai(arr)

      //    fl(0,n){
      //        printbin(arr[i]);
      //    }

      vi xp(n);
  x = 0;
  fl(0, n) {
    x ^= arr[i];
    xp[i] = x;
  }
  vi yp(n);
  x = 0;
  rfl(n - 1, 0) {
    x ^= arr[i];
    yp[i] = x;
  }

  int sex = 0;
  for (int b = 0; b < 31; b++) {
    // prefix to calculated number of places with set bit and
    // number of places of unset bit
    vvi pref(2, vi(n));
    int e = 0, o = 0;
    int x = 0;
    fl(0, n) {
      x ^= checkbit(arr[i], b);
      if (x == 1)
        o++;
      else
        e++;
      pref[1][i] = o;
      pref[0][i] = e;
    }
    vvi suff(2, vi(n));
    e = 0, o = 0;
    x = 0;
    rfl(n - 1, 0) {
      x ^= checkbit(arr[i], b);
      if (x == 1)
        o++;
      else
        e++;
      suff[1][i] = o;
      suff[0][i] = e;
    }

    fl(0, n) {
      if (msb(arr[i]) == b) {
        // calculate number of pairs of l and r
        // 0 == even
        // 1 == odd

        int z = checkbit(xp[i], b);
        int p = checkbit(yp[i], b);

        // set set unset
        int l = (i == 0 ? 0 : suff[!p][0] - suff[!p][i]);
        int r = (i == n - 1 ? 0 : pref[z][n - 1] - pref[z][i]) + 1;
        sex += (l * r);

        // unset set set
        l = (i == 0 ? 0 : suff[p][0] - suff[p][i]) + 1;
        r = (i == n - 1 ? 0 : pref[!z][n - 1] - pref[!z][i]);
        sex += (l * r);
      }
    }
  }
  co sex ed
}

signed main() {
  Code By NeverSpot test(t) {
    //          cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}
