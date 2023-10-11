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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  vector<vector<tuple<int, int, int>>> stages(n);
  set<int> stimes{0};
  for (auto &shows : stages)
  {
    int m;
    cin >> m;
    while (m--)
    {
      int start, end, pts;
      cin >> start >> end >> pts;
      shows.emplace_back(start, end, pts);
      stimes.insert(start);
      stimes.insert(end);
    }
  }

  vector<vector<int>> dp(1 << n, vector<int>(stimes.size(), INT_MIN));
  vector<int> times(all(stimes));
#define index(x) (lower_bound(all(times), x) - times.begin())

  dp[0][0] = 0;
  for (int i = 1; i < (int)times.size(); i++)
  {
    for (int mask = 0; mask < (1 << n); mask++)
    {
      dp[mask][i] = dp[mask][i - 1];
      for (int j = 0; j < n; j++)
      {
        if (not (mask & (1 << j)))
          continue;

        for (auto [start, end, pts] : stages[j])
        {
          if (end != times[i])
            continue;

          dp[mask][i] = max({dp[mask][i], dp[mask][index(start)] + pts, dp[mask ^ (1 << j)][index(start)] + pts});
        }
      }
    }
  }

  cout << (dp.back().back() < -1000010 ? -1 : dp.back().back()) << '\n';
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
 
