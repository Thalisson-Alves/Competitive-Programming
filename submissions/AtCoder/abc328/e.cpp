#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

struct UFDS {
  vector<int> ps, sz;
  int components;
  set<int> reps;

  UFDS(int n) : ps(n), sz(n, 1), components(n)
  {
    iota(all(ps), 0);
    for (int i = 0; i < n; i++) reps.insert(i);
  }

  int find_set(int x)
  {
    return (x == ps[x] ? x : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  bool union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);

    if (x == y) return false;

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    reps.erase(y);

    components--;
    return true;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e(m);
  for (auto &[a, b] : e) cin >> a >> b, --a, --b;
  UFDS ufds(n);
  vector<ll> ans(m);
  ll sum = 1ll*n*(n-1)/2;
  for (int i = m-1; ~i; --i) {
    auto a = ufds.sz[ufds.find_set(e[i].first)];
    auto b = ufds.sz[ufds.find_set(e[i].second)];
    ans[i] = sum;
    if (ufds.union_set(e[i].first, e[i].second)) sum -= a*b;
  }
  for (int i = 0; i < m; i++)
    cout << ans[i] << '\n';
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
