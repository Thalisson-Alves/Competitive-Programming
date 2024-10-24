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
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int x;
      cin >> x;
      st.insert(x);
    }
    else if (t == 1) cout << *begin(st) << '\n', st.erase(begin(st));
    else cout << *rbegin(st) << '\n', st.erase(prev(end(st)));
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
