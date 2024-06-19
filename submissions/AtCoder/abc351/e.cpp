#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> ex, ey, ox, oy;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if ((x + y) & 1) ox.push_back((x+y-1)/2), oy.push_back((x-y-1)/2);
    else ex.push_back((x+y)/2), ey.push_back((x-y)/2);
  }

  auto sum = [&](vector<int> &a) {
    sort(begin(a), end(a));
    ll res = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      res += 1ll*i*a[i];
      res -= 1ll*((int)a.size()-1-i)*a[i];
    }
    return res;
  };

  cout << sum(ex)+sum(ey)+sum(ox)+sum(oy) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
