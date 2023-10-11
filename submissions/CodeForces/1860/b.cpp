#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  ll m, k, a, b;
  cin >> m >> k >> a >> b;

  dbg(m);
  ll can_a = m - min(a, m);
  can_a = min(m, can_a + (can_a % k ? k - (can_a % k) : 0));
  ll amount_a = m - can_a;
  dbg(can_a, amount_a);
  m -= amount_a;
  a -= amount_a;

  ll amount_b = min(m / k, b);
  m -= k * amount_b;
  b -= amount_b;

  auto [d,r] = div(m,k);
  cout << d+r-min(a,r) << '\n';
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
