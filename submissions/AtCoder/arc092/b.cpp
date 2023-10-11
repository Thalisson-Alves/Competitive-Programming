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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
 
template<typename T>
vector<T> split(const string &s);
ll fpow(ll x, ll p);

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  ll ans = 0;
  for (int bits = 0; bits < 29; bits++)
  {
    ll p = 1ll << bits;
    ll mod = (1ll << (bits + 1)) - 1;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) v[i] = a[i] & mod;
    sort(all(v));

    ll ones = 0;
      
    for (auto x : b)
    {
      x &= mod;
      ones += lower_bound(all(v), 2*p - x) - lower_bound(all(v), p - x);
      ones += lower_bound(all(v), 4*p - x) - lower_bound(all(v), 3*p - x);
    }

    if (ones & 1) ans ^= p;
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

template<typename T>
vector<T> split(const string &s)
{
  vector<T> ans;
  stringstream ss(s);
  for (T x; ss >> x; ans.push_back(x));
  return ans;
}
 
ll fpow(ll x, ll p)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1);
  ans *= ans;
  if (p & 1) ans *= x;
  return ans;
}

