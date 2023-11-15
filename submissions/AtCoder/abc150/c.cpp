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
  vector<ll> p(n), q(n);
  for (auto &x : p) cin >> x;
  for (auto &x : q) cin >> x;
  vector<ll> a(n);
  iota(all(a), 1);
  int pp = -1, pq = -1, cur = 0;
  do
  {
    if (a == p) pp = cur;
    if (a == q) pq = cur;
    cur++;
  }while(next_permutation(all(a)));

  cout << abs(pp - pq) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
