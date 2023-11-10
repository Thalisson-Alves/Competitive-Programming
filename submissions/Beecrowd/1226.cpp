#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

ll count_valid(const string &s, int pos, bool at_max, bool prev_one, auto &memo) {
  if (pos >= (int)s.size()) return 1;
  auto &res = memo[pos][at_max][prev_one];
  if (res != -1) return res;

  res = 0;
  for (int i = 0; i < 10; i++) {
    if (at_max and i > s[pos] - '0') break;
    if (i == 4 or (prev_one and i == 3)) continue;
    res += count_valid(s, pos+1, at_max and s[pos]-'0' == i, i == 1, memo);
  }
  return res;
}

void solve()
{
  ll dp[20][2][2];

  for (ll n; cin >> n;) {
    ull l = 0, r = numeric_limits<ull>::max();
    while (l <= r) {
      memset(dp, -1, sizeof(dp));
      auto mid = l + (r - l) / 2;
      auto value = count_valid(to_string(mid), 0, 1, 0, dp);
      if (value-1 < n) l = mid + 1;
      else r = mid - 1;
    }

    cout << l << '\n';
  }
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
