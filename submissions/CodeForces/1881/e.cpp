#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

ll dp(const vector<int> &v, int u, vector<ll> &memo) {
  if (u >= (int)v.size()) return 0;
  if (memo[u] != -1) return memo[u];
  auto x = dp(v, u+1, memo);
  if (x != LLONG_MAX) x++;

  ll y = (u+v[u] >= (int)v.size() ? LLONG_MAX : dp(v, u+v[u]+1, memo));
  return memo[u] = min(x, y);
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;

  vector<ll> memo(n, -1);
  cout << dp(v, 0, memo) << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
