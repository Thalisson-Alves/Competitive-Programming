#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define NDEBUG
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> hs(n);
  for (auto &x : hs) cin >> x;
  vector<int> mx(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a>> b;
    --a, --b;
    mx[a] = max(mx[a], hs[b]);
    mx[b] = max(mx[b], hs[a]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += hs[i] > mx[i];
  cout << ans << '\n';
}

int main()
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

