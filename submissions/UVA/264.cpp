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
  for (int n; cin >> n;)
  {
    cout << "TERM " << n << " IS ";
    ll ans = 1, cols = 1;
    for (;; cols++)
    {
      ll x = ((cols & 1) ? 1 : 2 * cols);
      if (ans + x > n) break;
      ans += x;
    }

    for (ll num = 1, den = cols; cols > 0; cols--, num++, den--, ans++)
    {
      if (ans == n)
      {
        cout << num<<'/'<<den<<'\n';
        break;
      }
      if (ans + 2*cols-1==n)
      {
        cout << num+1<<'/'<<den<<'\n';
        break;
      }
    }
  }
}

// 1 2 6 7 15 16

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

