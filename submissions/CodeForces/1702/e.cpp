#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<vector<int>> g(n);
  for (auto &[a, b] : v) {
    cin >> a >> b, --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> vis(n);
  queue<int> q;
  for (int i = 0; i < n; i++) if (not vis[i]) {
    vis[i] = 1;
    q.push(i);
    bool cant = 1;
    while (not q.empty()) {
      auto cur = q.front();
      q.pop();

      if (g[cur].size() != 2 or g[cur][0] == cur or g[cur][1] == cur) {
        cout << "NO\n";
        return;
      }
      for (auto x : g[cur]) if (not vis[x]) {
        vis[x] = 1;
        q.push(x);
        cant ^= 1;
      }
    }

    if (cant) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int32_t main()
{
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
