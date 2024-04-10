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
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<int> mp(26);
  iota(all(mp), 0);
  while (q--) {
    char a, b;
    cin >> a >> b;
    a -= 'a';
    b -= 'a';
    for (auto &x : mp)
      if (x == a) x = b;
  }
  for (auto &x : s) x = 'a' + mp[x - 'a'];
  cout << s << '\n';
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
