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

ll fpower(ll a, ll b, ll m)
{
  if (b == 0) return 1;
  ll ans = fpower(a, b >> 1, m);
  ans = (ans * ans) % m;
  if (b & 1) ans = (ans * a) % m;
  return ans;
}

void solve()
{
  ll ans = 1;
  deque<int> s{1};
  ll const mod = 998244353;
  dbg(fpower(10, 2, mod));
  int q; cin >> q;
  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int x;
      cin >> x;
      s.push_back(x);

      ans = (ans * 10 + x) % mod;
    }
    else if (t == 2)
    {
      ans = (ans - s.front() * fpower(10, s.size() - 1, mod)) % mod;
      if (ans < 0) ans += mod;
      s.pop_front();
    }
    else
      cout << ans << '\n';
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

