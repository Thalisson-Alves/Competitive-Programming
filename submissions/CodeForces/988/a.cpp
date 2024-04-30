#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x] = i;
  }
  if ((int)mp.size() < k) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for (auto [_, i] : mp) {
    cout << i + 1 << ' ';
    if (!--k) break;
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
