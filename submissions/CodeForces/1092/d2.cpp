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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int mx = *max_element(a.begin(), a.end());
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx and st.size()) {
      cout << "NO\n";
      return;
    }
    if (a[i] == mx) continue;
    if (st.size() and st.top() == a[i]) st.pop();
    else if (st.empty() or st.top() > a[i]) st.push(a[i]);
    else {
      cout << "NO\n";
      return;
    }
  }
  cout << (st.empty() ? "YES" : "NO") << '\n';
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
