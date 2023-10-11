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
  ll x;
  cin >> x;
  vector<ll> ans;
  ll anss = 0;
  while (x & (x+1))
  {
    anss++;
    ll last = 0;
    for (ll i = 0; (1ll << i) < x; i++)
      if (((1ll<<i) & x) == 0)
        last = i;

    ans.push_back(last + 1);
    x ^= (1ll << ans.back()) - 1;

    if (x & (x+1)) x++, anss++;
  }

  cout << anss << '\n';
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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

