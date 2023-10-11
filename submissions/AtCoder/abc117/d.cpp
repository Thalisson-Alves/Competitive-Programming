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

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n), counter(50, n);
  for (auto &x : v)
  {
    cin >> x;
    for (ll i = 0; i < (ll)counter.size(); i++)
      if (x & (1ll << i)) counter[i]--;
  }

  ll ans = 0;
  for (ll i = counter.size()-1; ~i; i--)
  {
    dbg(ans, counter[i], (1ll << i));
    if ((2 * counter[i] >= n) and (ans | (1ll << i)) <= k)
      ans |= (1ll << i);
  }

  ll sum = 0;
  for (auto x : v) sum += x ^ ans;

  cout << sum << '\n';
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

