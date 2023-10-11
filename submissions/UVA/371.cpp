#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ll acker(ll n)
{
  ll ans = 0;
  do
  {
    n = (n&1?3*n+1:n>>1);
    ans++;
  } while(n != 1);

  return ans;
}

void solve()
{
  for (ll a, b; cin >> a >> b, a or b;)
  {
    if (a > b) swap(a, b);
    pair<ll, ll> ans;
    for (ll i = a; i <= b; i++)
    {
      auto ac = acker(i);
      if (ac > ans.first)
        ans = {ac, i};
    }
    cout << "Between " << a << " and " << b << ", " << ans.second << " generates the longest sequence of " << ans.first << " values.\n";
  }
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

