#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto &x : b) cin >> x;
  int l;
  cin >> l;
  vector<int> c(l);
  for (auto &x : c) cin >> x;
  set<int> can;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < l; k++) {
        can.insert(a[i] + b[j] + c[k]);
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << (can.count(x) ? "Yes" : "No") << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
