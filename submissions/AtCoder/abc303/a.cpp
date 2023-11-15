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
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool ans = true;
  map<char, char> sim{{'1','l'},{'0','o'}};
  for (int i = 0; ans and i < n; i++)
  {
    if (a[i] != b[i] and sim[a[i]] != b[i] and sim[b[i]] != a[i])
      ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
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

