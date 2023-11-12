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

vector<int> bfs(const vector<vector<double>> &g, const int s)
{
  vector<double> dist(g.size(), -1);
  dist[s] = 1;

  queue<tuple<double, int, vector<int>>> q;
  q.emplace(1, s, vector<int>{s});

  while (not q.empty())
  {
    auto [cost, cur, path] = q.front(); q.pop();
    if (path.size() > g.size()) break;

    if (cost * g[cur][s] >= 1.01) {
      path.push_back(s);
      return path;
    }

    for (int i = 0; i < (int)g.size(); i++)
    {
      auto new_cost = cost * g[cur][i];
      if (new_cost > dist[i])
      {
        dist[i] = new_cost;
        path.push_back(i);
        q.emplace(new_cost, i, path);
        path.pop_back();
      }
    }
  }

  return {};
}

void solve()
{
  for (int n; cin >> n;) {
    vector<vector<double>> mat(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
      mat[i][i] = 1.0;
      for (int j = 0; j < n-1; j++) {
        cin >> mat[i][j+(j>=i)];
      }
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
      auto d = bfs(mat, i);
      if (d.size() and (res.empty() or res.size() > d.size()))
        swap(res, d);
    }

    if (res.empty()) {
      cout << "no arbitrage sequence exists\n";
    }

    for (int j = 0; j < (int)res.size(); j++)
      cout << res[j] + 1 << " \n"[j==(int)res.size()-1];
  }
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
