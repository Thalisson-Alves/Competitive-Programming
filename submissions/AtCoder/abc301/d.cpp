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
 
template<typename T>
vector<T> split(const string &s);
ll fpow(ll x, ll p);

ll func(ll b, ll n)
{
  auto [d, r] = div(n, b);
  return (n < b ? r : func(b, d) + r);
}

void solve()
{
  string s;
  cin >> s;
  ull n;
  cin >> n;
  reverse(all(s));

  ull ans = 0;
  for (ll i = s.size() - 1; ~i; i--)
    if (s[i] == '1')
    {
      ans |= (1ull << i);
      dbg(i, s[i], ans);
    }

  if (ans > n)
  {
    cout << "-1\n";
    return;
  }

  for (ll i = s.size() -1; ~i; i--)
    if (s[i] == '?' and (ans | (1ull << i)) <= n)
      ans |= (1ull << i);

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

