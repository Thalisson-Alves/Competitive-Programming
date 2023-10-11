#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  ll b, q, l, m;
  cin >> b >> q >> l >> m;
  vector<ll> bad(m);
  for (auto &x : bad) cin >> x;
  sort(all(bad));

  if (abs(b) > l)
  {
    cout << "0\n";
    return;
  }

  if (q == 1)
  {
    cout << (binary_search(all(bad), b) ? "0" : "inf") << '\n';
    return;
  }

  if (q == -1)
  {
    bool p = binary_search(all(bad), b);
    bool n = binary_search(all(bad), -b);

    cout << (n and p ? "0" : "inf") << '\n';
    return;
  }

  if (q == 0 or b == 0)
  {
    if (not binary_search(all(bad), 0))
      cout << "inf\n";
    else if (not binary_search(all(bad), b))
      cout << "1\n";
    else
      cout << "0\n";
    return;
  }

  ll last = (log2(l) - log2(abs(b))) / log2(abs(q));
  ll ans = 0;
  for (ll i = 0, k = 1; i <= last; i++, k *= q)
    ans += not binary_search(all(bad), b * k);

  cout << ans << '\n';
}

// b * q^x <= l
// q^x <= l / b
// x * log(q) <= log(l / b)
// x <= log(l / b) / log(q)
// x <= (log(l)-log(b))/log(q)

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

