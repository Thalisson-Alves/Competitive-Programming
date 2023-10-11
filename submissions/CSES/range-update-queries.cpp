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
  int n, q;
  cin >> n >> q;
  SegTree<ll> st(n);

  for (int i = 0, x; i < n and cin >> x; i++)
    st.update(i, x);

  while (q--)
  {
    int t, a;
    cin >> t >> a;
    if (t == 1)
    {
      int b, u;
      cin >> b >> u;
      st.update(a-1, b-1, u);
    }
    else
      cout << st.range_sum(a-1, a-1) << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

