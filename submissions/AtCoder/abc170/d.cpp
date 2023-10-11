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

ll MAX_N = 1e6;
vector<char> is_ok(MAX_N+1, true);
void mark(int i)
{
  if (not is_ok[i]) return;
  for (ll j = i*2; j <= MAX_N; j+=i)
    is_ok[j] = false;
}

void solve()
{
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    mp[x]++;
  }

  for (auto [a, b] : mp)
  {
    mark(a);
    if (b > 1) is_ok[a] = false;
  }

  int ans = 0;
  for (auto [a, _] : mp)
    ans += is_ok[a];
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
    solve();
 
  return 0;
}

