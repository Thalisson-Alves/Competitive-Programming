#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  ll n;
  cin >> n;
  map<ll, ll> mp;
  mp[n] = 1;
  ll res = 0;
  while (mp.rbegin()->first > 1) {
    auto it = prev(mp.end());
    res += it->first * it->second;
    mp[(it->first / 2)] += it->second;
    mp[((it->first + 1) / 2)] += it->second;
    mp.erase(it);
  }
  cout << res << '\n';
}

int32_t main() {
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
