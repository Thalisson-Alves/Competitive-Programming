#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

bool bipartite_matching(const vector<vector<int>> &g, int u, vector<bool> &vis, vector<int> &matching) {
  if (vis[u]) return false;
  vis[u] = 1;
  for (auto v : g[u]) {
    if (matching[v] == -1 or bipartite_matching(g, v, vis, matching)) {
      matching[v] = u;
      return true;
    }
  }
  return false;
}

vector<int> bipartite_matching(const vector<vector<int>> &g) {
  vector<int> matching(g.size(), -1);
  vector<bool> vis(g.size());
  for (int i = 0; i < (int)g.size(); i++) {
    vis.assign(g.size(), 0);
    bipartite_matching(g, i, vis, matching);
  }
  return matching;
}

void solve()
{
  int n;
  cin >> n;
  vector<string> a(n);
  unordered_map<string, int> mp;
  for (auto &x : a) {
    cin >> x;
    mp[x] = mp.size();
  }
 
  int m;
  cin >> m;
  vector<set<int>> pos(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pos[i].insert(j);
    }
  }
 
  while (m--) {
    int r, w;
    cin >> r >> w;
    --w;
    set<int> v;
    for (int i = 0; i < r; i++) {
      string s;
      cin >> s;
      v.insert(mp[s]);
    }
 
    for (int i = 0; i < n; i++) {
      if (!v.count(i))
        pos[w].erase(i);
    }
 
    for (int i = 0; i < w; i++) {
      for (auto x : v) {
        pos[i].erase(x);
      }
    }
  }

  vector<vector<int>> bipartite(2*n+1);
  for (int i = 0; i < n; i++) {
    for (auto x : pos[i]) {
      bipartite[x+n].push_back(i);
    }
  }

  auto ans = bipartite_matching(bipartite);
  dbg(ans);
  for (int i = 0; i < n; i++) {
    cout << a[ans[i]-n] << ' ';
  }
  cout << '\n';
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
