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
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  for (int i = 0; i < n-2; i++) {
    if (v[i] == "sweet" and v[i+1] == v[i]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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
