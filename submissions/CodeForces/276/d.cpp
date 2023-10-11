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
  ull l, r;
  cin >> l >> r;
  ull ans = 0;

  const ll n = 64;
  for (ll i = n-1; ~i; i--)
  {
    if (ans) ans |= 1ull << i;
    else if ((l&(1ull<<i))!=(r&(1ull<<i)))
      ans |= 1ull << i;
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

