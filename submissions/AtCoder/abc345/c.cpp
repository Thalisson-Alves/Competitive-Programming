#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve()
{
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto c : s)
    ++mp[c];
  ll res = (mp.size() != s.size());
  set<char> st;
  for (int i = 0; i < (int)s.size(); i++) {
    res += (int)s.size() - i - 1 - --mp[s[i]];
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
