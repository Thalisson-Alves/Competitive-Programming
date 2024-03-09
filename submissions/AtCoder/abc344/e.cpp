#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

void solve()
{
  int n;
  cin >> n;
  list<int> ls;
  map<int, list<int>::iterator> mp;
  for (int i = 0; i < n; i++) {
    cin >> ls.emplace_back();
    mp[ls.back()] = prev(ls.end());
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      auto it = ls.insert(next(mp[x]), y);
      mp[y] = it;
    } else {
      int x;
      cin >> x;
      ls.erase(mp[x]);
      mp.erase(x);
    }
  }
  for (auto x : ls) cout << x << ' ';
  cout << '\n';
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
