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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;

  vector<ll> pows(15, 1), nines(15, 0);
  for (int i = 1; i < (int)pows.size(); i++)
  {
    pows[i] = pows[i-1] * 10;
    nines[i] = nines[i-1] * 10 + 9;
  }

  ll d = (ll)log10(n) + 1;

  ll nfirst = n / pows[d - 1];
  ll nlast = n % 10;
  ll mid = d >= 2 ? (n / 10) % pows[d - 2] : 0;

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i % 10 == (i / pows[(ll)log10(i)]))
      ans++;

    if (i % 10 == 0)
    {
      dbg(i, ans);
      continue;
    }

    for (int j = 0; j < d - 2; j++)
      ans += nines[j] + 1;

    if (d == 1) continue;
    if (i % 10 < nfirst)
      ans += nines[d-2] + 1;
    else if (i % 10 == nfirst)
      ans += mid + (nlast >= i / pows[(ll)log10(i)]);

    dbg(i, ans);
  }

  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
