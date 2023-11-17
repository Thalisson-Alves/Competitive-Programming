#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  {
    int mx = *max_element(all(v));
    if (mx <= 0) {
      cout << mx << "\n";
      return;
    }
  }

  int res = 0, sum = 0, p = -1;
  for (int i = 0; i < n; i++) {
    if (sum <= 0) {
      sum = 0;
      p = -1;
    }

    if ((v[i]&1)!=p) {
      sum += v[i];
      res = max(res, sum);
      p = v[i]&1;
    } else {
      sum = v[i];
      res = max(res, sum);
      p = v[i]&1;
    }
  }
  cout << res << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
