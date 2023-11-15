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

ll power(ll a, ll b, ll m)
{
  if (b == 0) return 1;
  ll ans = power(a, b >> 1, m);
  ans = ans * ans % m;
  if (b&1) ans = ans * a % m;
  return ans;
}

void solve()
{
  ll a, x, m;
  cin >> a >> x >> m;

  const int n = 40;
  vector<ll> basis(n, 1), powers(n, a%m);
  for (int i = 0; i < n-1; i++)
    basis[i+1] = basis[i] * (power(a, 1ll << i, m) + 1) % m;
  for (int i = 0; i < n-1; i++)
    powers[i+1] = powers[i] * powers[i] % m;

  dbg(basis);
  dbg(powers);

  ll ans = 0, times = 1;
  for (int i = n - 1; ~i; --i)
  {
    if ((x & (1ll << i)) == 0) continue;

    ans = (ans + basis[i] * times) % m;
    times = times * powers[i] % m;

    x -= 1ll << i;
  }

  cout << ans << '\n';
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

