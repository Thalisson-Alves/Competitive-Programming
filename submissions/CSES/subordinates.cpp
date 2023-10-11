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

ll count_sub(const vector<vector<int>> &tree, int i, vector<ll> &memo)
{
  if (tree[i].empty())
    return memo[i] = 0;

  ll sum = tree[i].size();
  for (auto x : tree[i])
    sum += count_sub(tree, x, memo);

  return memo[i] = sum;
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  for (int i = 1; i < n; i++)
  {
    int x;
    cin >> x;
    --x;
    tree[x].push_back(i);
  }

  vector<ll> ans(n);
  count_sub(tree, 0, ans);
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
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
 
