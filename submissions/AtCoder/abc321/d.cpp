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
  ll n, m, p;
  cin >> n >> m >> p;
  vector<ll> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  sort(all(a));
  sort(all(b));

  vector<ll> pref(m+1);
  for (int i =0 ; i < m; i++)
    pref[i+1] = pref[i] + b[i];

  ll ans = 0;
  for (auto x : a) {
    auto low = upper_bound(all(b), p-x)-b.begin();
    ans += low * x + pref[low];
    ans += (m-low) * p;
    dbg(m-low, pref.back() - pref[low]);
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
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

