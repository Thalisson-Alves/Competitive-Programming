#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

struct BinaryLifting
{
  vector<int> far, level, parent;

  BinaryLifting(vector<int> &ps) : far(ps.size(), -1), level(ps.size()), parent(ps)
  {
    level[0] = 1;
    for (int i = 1; i < (int)parent.size(); i++)
    {
      level[i] = level[parent[i]] + 1;

      int p1 = parent[i];
      int p2 = far[p1];

      if (p2 > -1 and far[p2] > -1 and level[p1] - level[p2] == level[p2] - level[far[p2]])
        far[i] = far[p2];
      else
        far[i] = p1;
    }
  }

  int query(int node, int k) const
  {
    while (node >= 0 and k > 0)
    {
      if (far[node] > -1 and level[node] - k <= level[far[node]])
      {
        k -= level[node] - level[far[node]];
        node = far[node];
      }
      else
      {
        k--;
        node = parent[node];
      }
    }

    return node;
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> ps(n, -1);
  for (int i = 1; i < n; i++)
    cin >> ps[i], ps[i]--;

  BinaryLifting bl(ps);

  while (q--)
  {
    int x, k;
    cin >> x >> k;
    auto ans = bl.query(x-1, k);
    cout << ans + (ans >= 0) << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
