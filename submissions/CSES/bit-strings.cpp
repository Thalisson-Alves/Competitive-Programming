#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define debug(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ll fpow(ll a, ll b, ll m)
{
  if (b == 0) return 1;
  ll ans = fpow(a, b >> 1, m);
  ans = ((ans%m) * (ans%m)) % m;
  if (b & 1) ans = (ans*a)%m;
  return ans % m;
}

void solve()
{
  ll n;
  cin >> n;
  cout << fpow(2, n, 1e9+7) << '\n';
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

