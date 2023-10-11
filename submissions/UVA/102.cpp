#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  while (true)
  {
    vector<array<ll, 3>> v(3);
    for (auto &x : v) for (auto &xx : x) if (not (cin >> xx)) return;

    vector<int> order(3);
    iota(all(order), 0);
    pair<ll, string> ans{LLONG_MAX, "ZZZ"};
    dbg(v);
    do
    {
      ll cost = 0;
      for (int i = 0; i < 3; i++)
      {
        for (int j = 0; j < 3; j++)
          cost += (i == j ? 0 : v[order[i]][j]);
      }

      dbg(ans, cost, order);
      if (cost <= ans.first)
      {
        string s = "|||";
        for (int i = 0; i < 3; i++)
          s[order[i]] = "BGC"[i];

        if (cost < ans.first or s < ans.second)
          ans.second = s;

        ans.first = cost;
      }
    }
    while (next_permutation(all(order)));
    cout << ans.second << ' ' << ans.first << '\n';
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

