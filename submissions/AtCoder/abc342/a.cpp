#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto c : s) mp[c]++;
  for (int i = 0; i < (int)s.size(); i++) {
    if (mp[s[i]] == 1) {
       cout << i + 1 << '\n';
       return;
    }
  }
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
