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
  ll n, h, a, c, q;
  cin >> n >> h >> a >> c >> q;
  priority_queue<ll, vector<ll>, greater<>> pq;

  ll ans = 0;
  pq.push(h);
  for (int i = 1; i < n; i++) {
    ans += (int)pq.size();
    ll nh = (a * h + c) % q;
    while (!pq.empty() and pq.top() <= nh) pq.pop();
    h = nh;
    pq.push(nh);
  }

  cout << ans << '\n';
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
