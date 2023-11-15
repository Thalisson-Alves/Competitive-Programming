#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<ll> ps(m);
  for (auto &x : ps) cin >> x;
  vector<string> a(n);
  for (int i =0 ; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<ll, priority_queue<ll>>> v(n);
  ll mx = 0, smx = 0;
  for (int i = 0; i < n; i++) {
    auto &[x, y] = v[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'o')
        x += ps[j];
      else
        y.push(ps[j]);
    }
    x += i;
    if (mx < x) {
      smx = mx;
      mx = x;
    } else if (smx < x) {
      smx = x;
    }
  }

  if (smx == mx) mx++;

  dbg(v);

  for (int i = 0; i < n; i++) {
    ll sum = v[i].first;
    ll ans = 0;
    while (sum < mx) {
      sum += v[i].second.top();
      v[i].second.pop();
      ans++;
    }
    cout << ans << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}
