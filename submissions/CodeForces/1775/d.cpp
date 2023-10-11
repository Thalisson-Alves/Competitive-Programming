#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
vector<int> fact(ll n)
{
  vector<int> ans;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n%i==0)
      ans.push_back((int)i);
 
    while (n%i == 0)
      n/=i;
  }
  if (n > 1)
    ans.push_back((int)n);
  return ans;
}

vector<int> reconstruct_path(const vector<int> &came_from, int s, int t)
{
  vector<int> path;
  path.push_back(t);
  for (auto cur = came_from[t]; cur != -1; cur = came_from[cur])
  {
    path.push_back(cur);
    if (cur == s) break;
  }
  reverse(path.begin(), path.end());
  return path;
}

vector<int> bfs(int s, int t, const vector<int> &v, map<int, vector<int>> &mp, map<int, vector<int>> &factors, int mx_prime)
{
  if (s == t)
    return {s};

  queue<int> q;
  q.push(s);
 
  vector<int> vis(v.size());
  vis[s] = true;
  vector<int> vis_prime(mx_prime + 10);
 
  vector<int> came_from(v.size(), -1);
  while (not q.empty())
  {
    auto cur = q.front();
    q.pop();
 
    for (auto x : factors[v[cur]])
    {
      if (vis_prime[x]) continue;
      vis_prime[x] = true;
 
      for (auto pos : mp[x])
      {
        if (vis[pos]) continue;
        vis[pos] = true;
        q.push(pos);
        came_from[pos] = cur;
 
        if (pos == t)
          return reconstruct_path(came_from, s, t);
      }
    }
  }

  return {};
}

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, vector<int>> factors;
  map<int, vector<int>> mp;
  int mx_prime = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    auto f = fact(v[i]);
    factors[v[i]] = f;
    for (auto x : f)
      mp[x].push_back(i), mx_prime = max(mx_prime, x);
  }
 
  int s, t;
  cin >> s >> t;
  s--, t--;

  auto path = bfs(s, t, v, mp, factors, mx_prime);
 
  if (path.empty())
  {
    cout << "-1\n";
    return;
  }
 
  cout << path.size() << '\n';
  for (int i = 0; i < (int)path.size(); i++)
    cout << path[i] + 1 << " \n"[i == (int)path.size() - 1];
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

