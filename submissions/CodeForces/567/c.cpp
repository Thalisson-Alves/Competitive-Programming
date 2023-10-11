#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

ll fact(ll n)
{
  ll ans = n;
  for (ll i = 2; i < n; i++) ans *= i;
  return ans;
}

void solve()
{
  ll n, k;
  cin >> n >> k;
  map<ll, vector<ll>> mp;
  for (int x, i = 0; cin >> x; i++)
    mp[x].push_back(i);

  ll ans = 0;
  for (auto [x, v] : mp)
  {
    if (k == 1 || x == 0)
    {
      if (v.size() < 6)
        ans += fact(v.size()) / (6 * max(1ll, ((ll)v.size())-3));
      else
        ans += v.size() * (v.size() - 1) * (v.size() - 2) / 6;
      continue;
    }

    auto v2 = mp.find(x * k);
    auto v3 = mp.find(x * k * k);
    if (v2 == mp.end() or v3 == mp.end()) continue;
    dbg(x, x*k, x*k*k);

    for (auto y : v2->second)
    {
      ll ca = upper_bound(all(v), y) - v.begin();
      ll cb = v3->second.end() - upper_bound(all(v3->second), y);

      ans += ca * cb;
      dbg(y, ca, cb, ans);
    }
  }

  cout << ans << '\n';
}

// 1 1 2 2 4 2 4 1 2 2
//
// 1 1 1 1 2 2 2 4 4 4
//
// 4 2 1 1 2 4 2 4 1 1 2 4

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

