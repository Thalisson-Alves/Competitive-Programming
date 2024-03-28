#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (auto &[a, b] : v)
    cin >> a >> b;
  sort(v.begin(), v.end(), [](const auto &a, const auto &b) { return a.second < b.second; });
  multiset<int> pq;
  int res = 0;
  for (auto [a, b] : v) {
    auto it = pq.upper_bound(a);
    if (it != pq.begin()) {
      ++res;
      pq.erase(prev(it));
      pq.insert(b);
    } else if ((int)pq.size() < m) {
      ++res;
      pq.insert(b);
    }
  }
  cout << res << '\n';
}

int32_t main() {
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
