#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  sort(all(v), [](const auto &a, const auto &b) { return a.second < b.second; });
  ll res = 0;
  for (int i = 0; i < n; i++) {
    priority_queue<int> pq;
    ll sum = 0;
    for (int j = i; j < n; j++) {
      sum += v[j].first;
      pq.push(v[j].first);
      while (pq.size() and sum + v[j].second - v[i].second > m) {
        sum -= pq.top();
        pq.pop();
      }
      res = max(res, (ll)pq.size());
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
