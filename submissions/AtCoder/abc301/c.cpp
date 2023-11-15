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

ll func(ll b, ll n)
{
  auto [d, r] = div(n, b);
  return (n < b ? r : func(b, d) + r);
}

void solve()
{
  string a, b;
  cin >> a >> b;
  map<char, int> mpa, mpb;
  for (auto x : a) mpa[x]++;
  for (auto x : b) mpb[x]++;

  set<char> po{'a','t','c','o','d','e','r'};
  for (auto x : a)
  {
    if (mpa[x] > mpb[x] and po.count(x))
    {
      auto dif = mpa[x] - mpb[x];
      mpb[x] += dif;
      mpb['@'] -= dif;
    }
    else if (mpb[x] > mpa[x] and po.count(x))
    {
      auto dif = mpb[x] - mpa[x];
      mpa[x] += dif;
      mpa['@'] -= dif;
    }

    if (mpa['@'] < 0 or mpb['@'] < 0)
    {
      cout << "No\n";
      return;
    }
  }
  for (auto x : b)
  {
    if (mpa[x] > mpb[x] and po.count(x))
    {
      auto dif = mpa[x] - mpb[x];
      mpb[x] += dif;
      mpb['@'] -= dif;
    }
    else if (mpb[x] > mpa[x] and po.count(x))
    {
      auto dif = mpb[x] - mpa[x];
      mpa[x] += dif;
      mpa['@'] -= dif;
    }

    if (mpa['@'] < 0 or mpb['@'] < 0)
    {
      cout << "No\n";
      return;
    }
  }
  dbg(mpa, mpb);

  cout << (mpa == mpb ? "Yes" : "No") << '\n';
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

