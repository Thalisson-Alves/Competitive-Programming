#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

struct UFDS {
  unordered_map<int, int> ps, sz;

  UFDS() { }

  int find(int x) {
    auto it = ps.find(x);
    if (it == ps.end()) return x;
    return it->second = find(it->second);
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;

    sz.try_emplace(x, 1);
    sz.try_emplace(y, 1);

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    return true;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<pair<int, int>>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v, --c;
    edges[c].emplace_back(u, v);
  }

  constexpr int MAX = 200;
  vector<UFDS> heavy;
  map<pair<int, int>, int> light;
  for (const auto &[_, e] : edges) {
    if ((int)e.size() >= MAX) {
      auto &ufds = heavy.emplace_back();
      for (auto [a, b] : e) ufds.join(a, b);
    } else {
      unordered_map<int, vector<int>> g(e.size());
      for (auto [a, b] : e) {
        g[a].push_back(b);
        g[b].push_back(a);
      }

      unordered_set<int> vis;
      queue<int> q;
      for (auto &[u, v] : g) if (not vis.count(u)) {
        q.push(u);
        vis.emplace(u);

        vector<int> comp{u};

        while (!q.empty()) {
          auto cur = q.front();
          q.pop();

          for (auto x : g[cur]) if (vis.emplace(x).second) {
            q.push(x);
            comp.push_back(x);
          }
        }

        for (int i = 0; i < (int)comp.size(); i++) {
          for (int j = i+1; j < (int)comp.size(); j++) {
            ++light[minmax(comp[i], comp[j])];
          }
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    auto it = light.find(minmax(u, v));
    int res = it == light.end() ? 0 : it->second;
    for (auto &ufds : heavy)
      res += ufds.same(u, v);
    cout << res << '\n';
  }
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
