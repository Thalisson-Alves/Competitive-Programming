#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  array<vector<int>, 3> mp;
  for (int i = 0; i < n; i++) {
    auto x = (s[i] == 'B' ? 2 : (s[i] == 'G'));
    mp[x].push_back(i);
  }

  dbg(mp);

  ll ans = 0;
  for (auto r : mp[0]) {
    for (auto g : mp[1]) {
      auto [i,j]=minmax(r,g);
      auto dif = j - i;
      dbg(i,j,dif);

      // left
      auto before = upper_bound(all(mp[2]), i);
      ans += before - mp[2].begin();
      ans -= binary_search(mp[2].begin(), before, i - dif);

      // right
      auto after = upper_bound(all(mp[2]), j);
      ans += mp[2].end()-after;
      ans -= binary_search(after, mp[2].end(), j+dif);
      dbg('P', ans);

      // middle
      ans += after - before;
      dbg(after - mp[2].begin(), before - mp[2].begin());
      ans -= !((j-i)&1) and binary_search(before, after, i+((j-i)>>1));
      dbg(ans);
    }
  }

  cout << ans << '\n';
}
 
int main()
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

