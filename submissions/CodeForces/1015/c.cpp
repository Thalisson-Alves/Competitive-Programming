#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum += a;
    v[i] = a - b;
  }
  sort(v.rbegin(), v.rend());

  int res = 0;
  for (res = 0; sum > m and res < n; res++)
    sum -= v[res];

  cout << (sum > m ? -1 : res) << '\n';
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
