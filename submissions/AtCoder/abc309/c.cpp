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

void solve()
{
  ll n, k;
  cin >> n >> k;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  ll sum = 0;
  for (int i = 0 ;i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    pq.emplace(a ,b);
    sum += b;
  }

  ll day = 1;
  while (not pq.empty() and sum > k)
  {
    auto tmp = pq.top();
    dbg(tmp);
    while (not pq.empty() and pq.top().first == tmp.first)
    {
      sum -= pq.top().second;
      pq.pop();
    }
    day = tmp.first + 1;
  }
  cout << day << '\n';
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

