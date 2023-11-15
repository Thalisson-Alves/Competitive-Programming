#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

template <typename T> struct SegTree {
  int N;
  vector<T> v, lazy;

  SegTree(int n) : N(n), v(4 * N), lazy(4 * N) {}
  SegTree(const vector<T> &xs) : N((int)xs.size()), v(4 * N), lazy(4 * N, 0) {
    for (int i = 0; i < N; i++)
      update(i, xs[i]);
  }

  void update(int i, T value) { update(i, i, value); }

  void update(int a, int b, T value) { update(1, 0, N - 1, a, b, value); }

  T range_sum(int a, int b) { return range_sum(1, 0, N - 1, a, b); }

private:
  void apply_propagation(int node, int l, int r) {
    v[node] += (r - l + 1) * lazy[node];
    propagate(node, l, r, lazy[node]);
    lazy[node] = 0;
  }

  void propagate(int node, int l, int r, T value) {
    if (l >= r)
      return;

    lazy[2 * node] += value;
    lazy[2 * node + 1] += value;
  }

  void update(int node, int l, int r, int a, int b, T value) {
    if (lazy[node])
      apply_propagation(node, l, r);

    if (a > r or b < l)
      return;

    if (a <= l and b >= r) {
      v[node] += (r - l + 1) * value;
      propagate(node, l, r, value);
      return;
    }

    auto m = l + (r - l) / 2;
    update(2 * node, l, m, a, b, value);
    update(2 * node + 1, m + 1, r, a, b, value);

    v[node] = v[2 * node] + v[2 * node + 1];
  }

  T range_sum(int node, int l, int r, int a, int b) {
    if (lazy[node])
      apply_propagation(node, l, r);

    if (a > r or b < l)
      return 0;

    if (a <= l and b >= r)
      return v[node];

    auto m = l + (r - l) / 2;
    auto x = range_sum(2 * node, l, m, a, b);
    auto y = range_sum(2 * node + 1, m + 1, r, a, b);
    return x + y;
  }
};

void solve()
{
  ll n, d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> v(n);
  for (auto &[x, y] : v) cin >> x >> y;
  sort(all(v));

  SegTree<ll> st(n+1);

  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    v[i].second -= st.range_sum(i, i);
    if (v[i].second <= 0) continue;
    ll amount = (v[i].second + a - 1) / a;
    ans += amount;

    auto it = upper_bound(all(v), make_pair(2*d+v[i].first, LLONG_MAX)) - v.begin() - 1;
    dbg(i, it);
    st.update(i, it, amount * a);
  }

  for (int i = 0; i < n; i++)
  {
    dbg(i, st.range_sum(i, i));
  }

  cout << ans << '\n';
}

int main()
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
 
