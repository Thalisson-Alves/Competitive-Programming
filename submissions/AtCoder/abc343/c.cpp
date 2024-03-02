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

  auto is_pal = [](ll x) -> bool {
    auto s = to_string(x);
    for (int i = 0; i < (int)s.size() / 2; i++) {
      if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
  };

  ll res = 0;
  for (ll i = 0; i*i*i <= n; i++) {
    if (is_pal(i*i*i)) {
       res = i*i*i;
    }
  }
  cout << res << '\n';
}

int32_t main()
{
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
