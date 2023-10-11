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
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
 
void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll, bool>> v;
  for (int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    v.emplace_back(a, false);
    v.emplace_back(b, true);
  }
  sort(all(v));
  ll ans = 0, c = 0;
  for (auto [_, b] : v)
    ans = max(ans, (b ? --c : ++c));
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

