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
  bool mn = (min_element(a.begin(), a.end()) - a.begin()) & 1;
  set<int> st;
  for (int i = 1; i <= n; i++) st.insert(i);
  vector<int> b(n);
  for (int i = mn + 1; i < n-1; i += 2)
    b[i] = n - a[i] + 2, st.erase(b[i]);
  for (int i = 0; i < n; i++) if (!b[i]) {
    auto it = prev(st.upper_bound(n-a[i]+1));
    b[i] = *it;
    st.erase(it);
  }

  for (int i = 0; i < n; i++)
    cout << b[i] << " \n"[i == n-1];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
