#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  set<int> st;
  for (int i = 0; i < n; i++)
    if (s[i]-'0') st.insert(i);
  while (q--) {
    int t, k;
    cin >> t >> k;
    if (t == 0) st.insert(k);
    else if (t == 1) st.erase(k);
    else if (t == 2) cout << st.count(k) << '\n';
    else if (t == 3) {
      auto it = st.lower_bound(k);
      cout << (it == end(st) ? -1 : *it) << '\n';
    }
    else {
      auto it = st.upper_bound(k);
      cout << (it == begin(st) ? -1 : *prev(it)) << '\n';
    }
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
