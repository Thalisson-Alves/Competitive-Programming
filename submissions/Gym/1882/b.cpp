#include <bits/stdc++.h>
using namespace std;
 
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
  set<ll> st;
  ll full = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ll value = 0;
    while (x--) {
      int a;
      cin >> a;
      --a;
      value |= 1ll << a;
    }
    full |= value;
    st.insert(value);
  }

  ll ans = 0;
  for (int i = 0; i < 60; i++) {
    ll res = 0;
    for (auto x : st) {
      if (x & (1ll << i)) continue;
      res |= x;
    }

    if (res != full)
      ans = max(ans, (ll)__popcount(res));
  }

  cout << ans << '\n';
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

