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
  int n;
  cin >> n;
  n <<= 1;
  vector<pair<ll, int>> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].first;
    pts[i].second = i;
  }

  set<pair<ll, int>> remain;
  vector<int> ord(n), comp(n);
  auto dfs1 = [&](auto &&self, int i, ll dist) -> void {
    remain.erase(pts[i^1]);

    while (!remain.empty()) {
      auto it = remain.lower_bound(make_pair(pts[i].first - dist, -1));
      if (it == remain.end() or it->first > pts[i].first + dist) break;
      if (it->second == i) ++it;
      if (it == remain.end() or it->first > pts[i].first + dist) break;
      self(self, it->second^1, dist);
    }

    ord.push_back(i);
  };
  auto dfs2 = [&](auto &&self, int i, ll dist) -> void {
    remain.erase(pts[i]);

    while (!remain.empty()) {
      auto it = remain.lower_bound(make_pair(pts[i^1].first - dist, -1));
      if (it == remain.end() or it->first > pts[i^1].first + dist) break;
      if (it->second == (i^1)) ++it;
      if (it == remain.end() or it->first > pts[i^1].first + dist) break;
      comp[it->second] = comp[i];
      self(self, it->second, dist);
    }
  };
  auto can = [&](ll dist) -> bool {
    ord.clear();
    comp.assign(n, -1);
    remain.insert(all(pts));
    for (int i = 0; i < n; i++) if (remain.count(pts[i^1])) {
      dfs1(dfs1, i, dist);
    }
    remain.insert(all(pts));
    int id = 0;
    for (int i = n-1; ~i; --i) if (comp[ord[i]] == -1) {
      comp[ord[i]] = id++;
      dfs2(dfs2, ord[i], dist);
    }
    for (int i = 0; i < n; i += 2) {
      if (comp[i] == comp[i|1])
        return false;
    }
    return true;
  };

  ll l = 0, r = INT_MAX;
  while (l <= r) {
    auto mid = midpoint(l, r);
    if (can(mid)) l = mid + 1;
    else r = mid - 1;
  }
  cout << l << '\n';
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
