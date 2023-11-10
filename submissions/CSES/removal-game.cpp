#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  ll sum = 0;
  for (auto &x : v) cin >> x, sum += x;

  vector<ll> row(n), nrow(n);
  for (int l = n-1; ~l; --l) {
    for (int r = l; r < n; r++) {
      if (l == r)
        row[l] = v[l];
      else
        row[r] = max(v[l] - nrow[r], v[r] - row[r-1]);
    }
    swap(row, nrow);
  }
  cout << (nrow[n-1]+sum)/2 << '\n';
}

int32_t main()
{
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
