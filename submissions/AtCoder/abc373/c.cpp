#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  int mxa = INT_MIN, mxb = mxa;
  for (int i = 0; i <n ; i++) {
    int x;
    cin >> x;
    mxa = max(mxa, x);
  }
  for (int i = 0; i <n ; i++) {
    int x;
    cin >> x;
    mxb = max(mxb, x);
  }
  cout << (ll)mxa+mxb << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
