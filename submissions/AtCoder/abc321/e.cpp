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

inline ll count_pra_baixo(const ll n, ll x, ll k)
{
  if (k < 0 or k > 63 or x > numeric_limits<ll>::max() / (1ll << k)) return 0;
  ll primeiro = x * (1ll << k);
  ll last = primeiro + (1ll << k) - 1;
  if (primeiro > n)
    return 0;
  return min(last, n) - primeiro + 1;
}

void solve()
{
  ll n, x, k;
  cin >> n >> x >> k;
  ll ans = count_pra_baixo(n, x, k--);
  for (ll cur = x; cur and ~k; cur >>= 1, --k)
  {
    cur += (cur&1?-1:1);
    if (cur == 0) break;
    ll oi = count_pra_baixo(n, cur, k-1);
    if (not k) oi++;
    dbg(cur, oi, k-1);
    ans += oi;
  }
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}
