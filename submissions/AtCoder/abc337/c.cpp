#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n, -1);
  int cur = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (~x)
      a[x - 1] = i;
    else
      cur = i;
  }

  cout << cur + 1;
  for (cur = a[cur]; ~cur; cur = a[cur])
    cout << ' ' << cur + 1;
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
