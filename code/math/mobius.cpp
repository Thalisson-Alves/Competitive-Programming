constexpr int MAXN = 1e6;
int lp[MAXN+1];
int mob[MAXN+1];
void calc_mobius() {
  lp[1] = mob[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    if (!lp[i]) {
      for (int j = i; j <= MAXN; j+=i)
        if (!lp[j]) lp[j] = i;
    }
    if (lp[i/lp[i]] == lp[i])
      mob[i] = 0;
    else
      mob[i] = -1 * mob[i / lp[i]];
  }
}
