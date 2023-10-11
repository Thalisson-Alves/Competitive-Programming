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
  ll n, c;
  char cu;
  cin >> n >> c >> cu;
  if (cu == 'T')
    c *= 1024 * 1024;
  else if (cu == 'G')
    c *= 1024;
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    pref[i + 1] = pref[i] + x;
  }
  ll r = n;
  ll lans = -1;
  for (int i = 0; i < n; i++) {
    if (pref.back() - pref[i] <= c) break;
    auto it = upper_bound(all(pref), c + pref[i]);
    auto p = (ll)(it - pref.begin() - 1);
    if (p - i < r) {
      r = p - i;
      lans = i + 1;
    }
  }

  cout << r << ' ' << lans << '\n';
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
