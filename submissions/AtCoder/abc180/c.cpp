#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

vector<ll> divisors(ll n) {
  vector<ll> d;
  for (ll i = 1; i*i <= n; i++) if (n%i == 0) {
    d.push_back(i);
    if (n/i != i) d.push_back(n/i);
  }
  return d;
}

void solve()
{
  ll n;
  cin >> n;
  auto ans = divisors(n);
  sort(all(ans));
  for (auto x: ans) cout << x << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
 
  return 0;
}
