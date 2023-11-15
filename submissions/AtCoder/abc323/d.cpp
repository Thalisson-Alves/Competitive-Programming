#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve()
{
  int n;
  cin >> n;
  map<ll, ll> mp;
  ll mx= 0;
  for (int i = 0; i < n; i++) {
    ll s, c;
    cin >> s >> c;
    mp[s] = c;
    mx = max(mx,s);
  }

  auto cur = mp.begin()->first;
  while (1) {
    if (mp[cur] > 1 and 2*cur <= mx) {
      mp[cur*2] += mp[cur] / 2;
      mp[cur] &= 1;
    }

    auto it = mp.upper_bound(cur);
    if (it == mp.end()) break;
    cur = it->first;
  }

  dbg(mp);

  ll ans = 0;
  for (auto [x,y] : mp) {
    ans += __popcount(y);
  }

  cout << ans << '\n';
}

int32_t main()
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
