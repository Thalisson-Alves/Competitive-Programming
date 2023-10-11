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
  int n, q;
  cin >> n >> q;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;

  map<ll, ll> even, odd;
  vector<ll> pref(n+1), zs(n+1), last(n, -1);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] ^ v[i-1];
    zs[i] = zs[i-1] + !v[i-1];

    if (i&1)
    {
      if (even.count(pref[i]))
        last[i-1] = even[pref[i]];
      odd[pref[i]] = i;
    }
    else
    {
      if (odd.count(pref[i]))
        last[i-1] = odd[pref[i]];
      even[pref[i]] = i;
    }
  }

  dbg(last);
  for (int l, r; cin >> l >> r;)
  {
    l--;
    if (zs[r] - zs[l] == r - l)
      cout << "0\n";
    else if (pref[r]^pref[l])
      cout << "-1\n";
    else if ((r-l)&1)
      cout << "1\n";
    else if (v[l] == 0 or v[r-1] == 0)
      cout << "1\n";
    else if (last[r-1] >= l)
      cout << "2\n";
    else
      cout << "-1\n";
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

