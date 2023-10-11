#include <bits/stdc++.h>
using namespace std;
 
// #ifdef DEBUG
// #include "debug.cpp"
// #else
#define dbg(...) 4269
// #endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

template<typename T> vector<T> split(const string &s)
{
  vector<T> ans;
  stringstream ss(s);
  for (T x; ss >> x; ans.push_back(x));
  return ans;
}

void solve()
{
  string s;
  getline(cin, s);

  auto v = split<ll>(s);
  dbg(v);
  ll ans = 0;
  for (int i = 0; i < (int)v.size(); i++)
    for (int j = i + 1; j < (int)v.size(); j++)
      ans = max(ans, __gcd(v[i], v[j]));
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

