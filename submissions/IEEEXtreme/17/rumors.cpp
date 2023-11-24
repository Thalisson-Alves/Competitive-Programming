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

void solve()
{
  int n;
  cin >> n;
  unordered_map<string, string> mp;
  unordered_map<string, vector<string>> g;
  for (int i = 0; i < n; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    if (b == "->") {
      mp[c] = a;
    }
    g[a].push_back(c);
    g[c].push_back(a);
  }

  vector<string> ans;
  unordered_set<string> vis;
  queue<string> q;
  for (auto &[first, _] : g) if (mp[first].size() and vis.emplace(first).second) {
    q.push(first);
    while (not q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto &x : g[cur]) if (x != mp[cur] and vis.emplace(x).second) {
        q.push(x);
        mp[x] = cur;
      }
    }
  }

  for (auto &[x, _] : g) if (mp[x].empty()) {
    ans.push_back(x);
  }

  sort(all(ans));
  for (auto &x : ans)
    cout << x << '\n';
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
