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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

template<typename T>
ll inversion_count(vector<T> &v, int l, int m, int r)
{
  vector<T> cv(v.begin() + l, v.begin() + r + 1);
  int a = 0, b = m+1-l, i = l;
  ll res = 0;
  while (a <= m-l and b <= r-l)
  {
    if (cv[a] > cv[b])
      v[i++] = cv[b++], res += m - a - l + 1;
    else
      v[i++] = cv[a++];
  }
  while (a <= m-l)
    v[i++] = cv[a++];
  while (b <= r-l)
    v[i++] = cv[b++];

  dbg(l, m, r, res);
  return res;
}

template<typename T>
ll inversion_count(vector<T> &v, int l, int r)
{
  if (l >= r)
    return 0;

  int m = l + (r - l) / 2;
  auto left = inversion_count(v, l, m);
  auto right = inversion_count(v, m+1, r);

  return left + right + inversion_count(v, l, m, r);
}

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  cout << inversion_count(v, 0, v.size()-1) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

