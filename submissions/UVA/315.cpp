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

// O(n + m)
struct BlockCutTree {
  vector<vector<int>> blocks, tree;
  vector<vector<pair<int, int>>> block_edges;
  vector<int> articulation, pos;

  BlockCutTree(const vector<vector<int>> &g) : articulation(g.size()), pos(g.size()) {
    int t = 0;
    vector<int> id(g.size(), -1);
    stack<int> s1;
    stack<pair<int, int>> s2;
    for (int i = 0; i < (int)g.size(); i++)
      if (id[i] == -1)
        dfs(g, i, -1, t, id, s1, s2);

    tree.resize(blocks.size());
    for (int i = 0; i < (int)g.size(); i++)
      if (articulation[i])
        pos[i] = (int)tree.size(), tree.emplace_back();

    for (int i = 0; i < (int)blocks.size(); i++) {
      for (auto j : blocks[i]) {
        if (not articulation[j]) pos[j] = i;
        else tree[i].push_back(pos[j]), tree[pos[j]].push_back(i);
      }
    }
  }

private:
  int dfs(const vector<vector<int>> &g, int i, int p, int &t, vector<int> &id, stack<int> &s1, stack<pair<int, int>> &s2) {
    int lo = id[i] = t++;
    s1.push(i);

    if (p != -1) s2.emplace(i, p);
    for (auto j : g[i])
      if (j != p and id[j] != -1)
        s2.emplace(i, j);

    for (auto j : g[i]) if (j != p) {
      if (id[j] == -1) {
        int val = dfs(g, j, i, t, id, s1, s2);
        lo = min(lo, val);

        if (val >= id[i]) {
          articulation[i]++;
          blocks.emplace_back(1, i);
          for (; blocks.back().back() != j; s1.pop())
            blocks.back().push_back(s1.top());

          block_edges.emplace_back(1, s2.top());
          s2.pop();
          for (; block_edges.back().back() != make_pair(j, i); s2.pop())
            block_edges.back().push_back(s2.top());
        }
      } else {
        lo = min(lo, id[j]);
      }
    }

    if (p == -1 and articulation[i]) --articulation[i];
    return lo;
  }
};

void solve()
{
  for (int t; cin >> t, cin.ignore(), t;) {
    vector<vector<int>> g(t);
    while (true) {
      string s;
      getline(cin, s);
      stringstream ss(s);
      int n;
      ss >> n;
      if (n == 0) break;

      --n;
      for (int x; ss >> x;) {
        g[n].push_back(--x);
        g[x].push_back(n);
      }
    }
    dbg(g);
    int ans = 0;
    for (auto art : BlockCutTree(g).articulation)
      ans += art > 0;
    cout << ans << '\n';
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
