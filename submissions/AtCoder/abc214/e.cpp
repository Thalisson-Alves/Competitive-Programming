#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    mp[l].push_back(r);
  }
  mp[2e9];
  priority_queue<int, vector<int>, greater<>> pq;
  bool res = 1;
  for (int i = mp.begin()->first; res and i < 2e9;) {
    auto it = mp.find(i);
    if (it != mp.end()) for (auto x : it->second) pq.push(x);
    if (pq.empty()) i = mp.upper_bound(i)->first;
    else {
      if (pq.top() < i) res = 0;
      else pq.pop();
      ++i;
    }
  }
  cout << (res ? "Yes" : "No") << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
