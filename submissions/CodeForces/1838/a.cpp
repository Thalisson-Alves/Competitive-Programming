#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

bool can(const vector<ll> &v, int a, int b)
{
  if (not binary_search(all(v), abs(v[a] - v[b])))
    return false;

  queue<ll> q;
  q.push(abs(v[a] - v[b]));

  set<ll> vis;
  vis.insert({v[a], v[b], q.front()});

  vector<ll> board{v[a], v[b]};
  while (not q.empty())
  {
    auto cur = q.front(); q.pop();
    for (auto x : vis)
    {
      if (binary_search(all(v), abs(cur - x)) and not vis.count(abs(cur - x)))
      {
        q.push(abs(cur - x));
        vis.insert(abs(cur - x));
        board.push_back(abs(cur - x));
      }
    }

    board.push_back(cur);
  }

  return set<ll>(all(board)) == set<ll>(all(v));
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  sort(all(v));

  dbg(v);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (can(v, i, j))
      {
        cout << v[i] << '\n';
        return;
      }

  cout << "WTF\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
