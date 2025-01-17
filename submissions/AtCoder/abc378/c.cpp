#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = mp.find(x);
    if (it == mp.end()) b[i] = -1;
    else b[i] = it->second + 1;
    mp[x] = i;
  }
  for (auto x : b) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
