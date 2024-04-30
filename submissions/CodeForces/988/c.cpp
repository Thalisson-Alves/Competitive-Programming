#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int t;
  cin >> t;
  vector<vector<int>> v(t);
  unordered_map<int, set<int>> can;
  vector<int> sums(t);
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    v[i].reserve(n);
    for (int x; n-- and cin >> x; v[i].push_back(x), sums[i] += x);
    for (auto x : v[i]) can[sums[i] - x].insert(i);
  }

  for (auto &[s, st] : can) {
    if (st.size() < 2)
      continue;
    auto a = *st.begin();
    auto b = *st.rbegin();
    auto r1 = find(v[a].begin(), v[a].end(), sums[a]-s) - v[a].begin();
    auto r2 = find(v[b].begin(), v[b].end(), sums[b]-s) - v[b].begin();

    cout << "YES\n";
    cout << a + 1 << ' ' << r1 + 1 << '\n';
    cout << b + 1 << ' ' << r2 + 1 << '\n';
    return;
  }

  cout << "NO\n";
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
