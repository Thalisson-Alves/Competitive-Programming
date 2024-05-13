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
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[--x]++;
  }
  vector<int> hist(n+1);
  for (int i = 0; i < n; i++) {
    hist[b[i]] += pos[i];
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += hist[a[i]];
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
