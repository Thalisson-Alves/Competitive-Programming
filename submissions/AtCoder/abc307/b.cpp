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

bool is_pali(string s)
{
  int n = s.size();
  for (int i = 0; i < n; i++)
    if (s[i] != s[n-i-1]) return false;
  return true;
}

void solve()
{
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  for (int i = 0 ; i < n; i++)
    for (int j = i+1; j < n; j++)
      if (is_pali(v[i] + v[j]) or is_pali(v[j] + v[i]))
      {
        cout << "Yes\n";
        return;
      }
  cout << "No\n";
  // for (int i  =0 ; i < n; i++)
  // {
  //   string s;
  //   cin >> s;
  //   mp[s]++;
  // }
  //
  // for (auto [x, y] : mp)
  // {
  //   auto s = x;
  //   reverse(all(s));
  //   if ((s == x and y > 1) or (s != x and mp.count(x)))
  //   {
  //     dbg(s);
  //     cout << "Yes\n";
  //     return;
  //   }
  // }
  // cout << "No\n";
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

