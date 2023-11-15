#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void cycles(const vector<int> &v, vector<int> &cost, int start, int value)
{
  while (not cost[start])
  {
    cost[start] = -value;
    start = v[start];
  }

  if (cost[start] != -value)
    return;

  cost[start] = (int)v.size();
  for (auto cur = v[start]; cur != start; cost[cur] = (int)v.size(), cur = v[cur]);
}

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n), cost(n);
  for (auto &x : v) cin >> x, --x;

  for (int i = 0; i < n; i++)
    if (not cost[i])
      cycles(v, cost, i, i+1);

  cout << count(all(cost), n) << '\n';
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

