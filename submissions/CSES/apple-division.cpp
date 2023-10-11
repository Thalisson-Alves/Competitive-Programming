#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

ll brute(const vector<ll> v, int i, ll acc, ll total)
{
  if (i == (int)v.size())
    return abs(total-2*acc);
  return min(brute(v, i+1, acc+v[i], total), brute(v, i+1, acc, total));
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> v(n);
  ll total = 0;
  for (auto &x : v) cin >> x, total += x;
  cout << brute(v, 0, 0, total) << '\n';
}

// 7 6 5 5 3
// total = 26
// 26-14 = 12


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

