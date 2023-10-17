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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll zeros = (ll)count(all(s), '0');
  auto digits = [](ll x) {
    array<int, 10> ds;
    ds.fill(0);
    int cnt = 0;
    while (x) {
      auto [d,m] = div(x, 10ll);
      ds[m]++;
      x = d;
      cnt++;
    }
    return make_pair(ds, cnt);
  };
  array<int, 10> hist;
  hist.fill(0);
  for (auto c : s)
    hist[c-'0']++;

  auto comp = [](const array<int, 10> &v, const array<int, 10> &hs) {
    for (int i = 1; i < 10; i++) {
      if (v[i] != hs[i]) return false;
    }
    return true;
  };

  ll ans = 0;
  for (ll i = 0;; i++) {
    auto x = i*i;
    auto [dig, ds] = digits(x);
    if (ds > n) break;
    if (n - zeros <= ds and ds <= n) {
      if (comp(dig, hist))
        ans++;
    }
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
