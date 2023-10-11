#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve()
{
  auto pref = [](ll x) {return x * (x + 1) / 2;};
  for (ll n; cin >> n, n > 0;)
  {
    pair<ll, ll> ans{n, n};

    for (ll mid = 1; mid*mid<=2*n; mid++)
    {
      ll start = n / mid - mid / 2;
      for (auto i = start;; i++)
      {
        ll sum = pref(i+mid - 1) - pref(i - 1);
        if (sum == n) ans = {i, i + mid - 1};
        if (sum >= n) break;
        if (sum < n) continue;
      }
    }

    cout << n << " = " << ans.first << " + ... + " << ans.second << '\n';
  }
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

