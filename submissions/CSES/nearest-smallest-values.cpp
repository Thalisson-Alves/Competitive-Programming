#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
  sort(all(v));
  set<int> st;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n and v[i].first == v[j].first; j++) {
      auto it = st.lower_bound(v[j].second);
      if (it == st.begin()) {
        ans[v[j].second] = 0;
      } else {
        it = prev(it);
        ans[v[j].second] = *it + 1;
      }
    }
    int j;
    for (j = i; j < n and v[i].first == v[j].first; j++)
      st.insert(v[j].second);

    i = j-1;
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
