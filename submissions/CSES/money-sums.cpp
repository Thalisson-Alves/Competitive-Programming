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

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  set<ll> ans;
  for (auto x : a)
  {
    set<ll> can;
    for (auto y : ans)
      can.insert(x+y);
    ans.insert(all(can));
    ans.insert(x);
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
}

int main()
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

