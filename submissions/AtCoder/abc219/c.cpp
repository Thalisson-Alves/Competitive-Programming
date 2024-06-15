#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s; cin >> s;
  vector<int> pos(26);
  for (int i = 0; i < 26; i++) pos[s[i]-'a'] = i;
  int n; cin >> n;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  vector<pair<string, int>> o(n);
  for (int i = 0; i < n; i++) {
    o[i].second = i;
    for (auto c : v[i]) {
      o[i].first += 'a' + pos[c-'a'];
    }
  }
  sort(o.begin(), o.end());
  for (auto &[_, i] : o) {
    cout << v[i] << '\n';
  }
}

// clang-format off
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
