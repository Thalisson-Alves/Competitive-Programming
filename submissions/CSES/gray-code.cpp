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
  int n;
  cin >> n;
  vector<string> ans{""};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0, sz = (int)ans.size(); j < sz; j++)
      ans.push_back(ans[sz-j-1]);

    for (int j = 0; j < (int)ans.size(); j++)
      ans[j].push_back(j < (int)ans.size() / 2 ? '0' : '1');
  }

  for (auto x : ans)
    cout << x << '\n';
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
