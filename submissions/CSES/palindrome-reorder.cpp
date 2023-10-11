#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define debug(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve()
{
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto c : s) mp[c]++;
  int count_odd = 0;
  char odd = 0;
  for (auto [k, v] : mp)
    if (v&1)
    {
      count_odd++;
      odd = k;
    }
  if (count_odd > 1)
  {
    cout << "NO SOLUTION\n";
    return;
  }

  if (not odd) odd = s[0];
  string ans(s.size(), odd);
  int idx = 0;
  for (auto [k, v] : mp)
  {
    for (int i = 1; i < v; i+=2, idx++)
    {
      ans[idx] = k;
      ans[ans.size()-idx-1] = k;
    }
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

