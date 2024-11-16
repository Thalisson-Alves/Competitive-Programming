#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  --k;
  vector<pair<int, int>> bl;
  for (int i = 0; i < n; i++) if (s[i] == '1') {
    if (bl.empty() or i != 1+bl.back().second)
      bl.emplace_back(i, i);
    else
      bl.back().second = i;
  }
  for (int i = 0; i <= bl[k].second-bl[k].first; i++) {
    swap(s[i+bl[k-1].second+1], s[i+bl[k].first]);
  }
  cout << s << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
