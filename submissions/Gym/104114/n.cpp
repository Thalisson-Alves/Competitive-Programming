#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) st.emplace(a[i], i);
  while (st.size()) {
    auto [x, i] = *st.rbegin();
    st.erase(prev(st.end()));
    for (int j : {i-1, i+1}) if (0 <= j and j < n and a[i]-a[j] > m) {
      st.erase({a[j], j});
      a[j] = a[i]-m;
      st.emplace(a[j], j);
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
