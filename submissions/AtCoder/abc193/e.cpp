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

constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
  a %= b;
  if (a < 0) a += b;
  if (a == 0) return {b, 0};

  ll s = b, t = a;
  ll m0 = 0, m1 = 1;

  while (t) {
    ll u = s / t;
    s -= t * u;
    m0 -= m1 * u;

    swap(s, t);
    swap(m0, m1);
  }

  if (m0 < 0) m0 += b / s;
  return {s, m0};
}

pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m) {
  assert(r.size() == m.size());

  ll r0 = 0, m0 = 1;
  for (int i = 0; i < (int)r.size(); i++) {
    auto r1 = r[i] % m[i], m1 = m[i];
    if (r1 < 0) r1 += m[i];
    if (m0 < m1) {
      swap(r0, r1);
      swap(m0, m1);
    }
    if (m0 % m1 == 0) {
      if (r0 % m1 != r1) return {0, 0};
      continue;
    }
    auto [g, im] = inv_gcd(m0, m1);
    if ((r1 - r0) % g) return {0, 0};
    ll u1 = (m1 / g);
    ll x = (r1 - r0) / g % u1 * im % u1;
    r0 += x * m0;
    m0 *= u1;
    if (r0 < 0) r0 += m0;
  }
  return {r0, m0};
}

void solve()
{
  ll x, y, p, q;
  cin >> x >> y >> p >> q;
  ll res = LLONG_MAX;
  for (ll t1 = x; t1 < x + y; t1++) {
    for (ll t2 = p; t2 < p + q; t2++) {
      auto [t, lcm] = crt({t1, t2}, {2*(x+y), p+q});
      if (not lcm) continue;
      res = min(res, t);
    }
  }
  if (res == LLONG_MAX) cout << "infinity\n";
  else cout << res << '\n';
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
