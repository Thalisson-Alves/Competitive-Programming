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

inline ll colisions(const vector<pair<int, int>> &a, int start, int x) {
  ll res = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    auto l = max(a[i].first - start - 1, 0) / x;
    auto r = max(a[i].first + a[i].second - start, 0) / x;
    res += (r - l);
    if (a[i].first <= start and start <= a[i].first + a[i].second) res++;
  }
  return res;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  sort(all(a));

  ll a1 = 0, a2 = LLONG_MAX;
  for (int i = 0; i <= 480; i++) {
    auto c = colisions(a, i, k);
    if (c < a2) {
      a2 = c;
      a1 = i;
    }
  }

  cout << a1 << ' ' << a2 << '\n';
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
