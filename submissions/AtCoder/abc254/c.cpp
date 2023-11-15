#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<multiset<int>> mp(k);
  for (int i = 0; i < n; i++)
    mp[i%k].insert(v[i]), pq.push(v[i]);

  string ans = "Yes";
  for (int i = 0; not pq.empty(); i++)
  {
    auto cur = pq.top(); pq.pop();
    auto it = mp[i%k].find(cur);
    if (it == mp[i%k].end())
    {
      ans = "No";
      break;
    }
    mp[i%k].erase(it);
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

