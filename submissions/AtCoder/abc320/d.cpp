#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> ps(n);
  vector<char> ok(n);
  ok[0] = 1;
  vector<vector<pair<int, pair<ll, ll>>>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, x ,y;
    cin >> a >> b >> x >> y;
    --a, --b;
    g[a].emplace_back(b, make_pair(x, y));
    g[b].emplace_back(a, make_pair(-x, -y));
  }

  queue<int> q;
  q.push(0);

  while (q.size()) {
    auto cur = q.front();
    q.pop();

    for (auto [b, p] : g[cur]) {
      if (ok[b]) continue;

      ok[b] = 1;
      ps[b] = {ps[cur].first + p.first, ps[cur].second + p.second};
      q.push(b);
    }
  }

  for (int i = 0; i < n; i++) {
    if (ok[i]) cout << ps[i].first << ' ' << ps[i].second << '\n';
    else cout << "undecidable\n";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
