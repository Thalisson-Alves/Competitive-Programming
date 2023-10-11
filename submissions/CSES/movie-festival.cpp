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
  ll n;
  cin >> n;
  using T = pair<ll, ll>;
  vector<T> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  sort(all(v), [](const T& a, const T& b)
  {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
  });
  ll ans = 0, c = 0, t = 0;
  for (auto [a, b] : v)
  {
    if (t <= a)
    {
      c++;
      t = b;
      ans = max(ans, c);
    }
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

