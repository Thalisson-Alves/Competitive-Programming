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

void solve()
{
  for (int n; cin >> n;) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first;
      v[--v[i].first].second = i;
    }
    vector<bool> vis(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      --x;
      vis[x] = 1;
      for (int j = 0; j < v[x].second; j++) {
        ans += not vis[v[j].first];
      }
    }
    cout << ans << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }

  return 0;
}
