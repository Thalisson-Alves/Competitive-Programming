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

template <typename T> struct MergeSortTree {
  int N;
  vector<vector<T>> v, idx;

  MergeSortTree(const vector<T> &a) : N((int)a.size()), v(4 * N), idx(4 * N) {
    vector<int> b(a.size());
    iota(all(b), 0);
    sort(all(b), [&a](int x, int y) { return a[x] < a[y]; });
    build(a, b, 1, 0, N-1);
  }

  // template <typename R, typename Q, auto F, auto op, R id=R()>
  // inline R query(int l, int r, Q x) const {
  //   return query<R, Q, F, op, id>(1, 0, N-1, l, r, x);
  // }
  // int count_in_range(int l, int r, T mn, T mx) const {
  //   constexpr auto f = [](const auto &a, auto x) {
  //     return (int)(lower_bound(all(a), x.second) - lower_bound(all(a), x.first));
  //   };
  //   constexpr auto op = [](int a, int b) {
  //     return a + b;
  //   };
  //   return query<int, pair<T, T>, f, op, 0>(l, r, make_pair(mn, mx));
  // }
  // int count_greater(int l, int r, T x) const {
  //   constexpr auto f = [](const auto &a, auto q) {
  //     return (int)(a.end() - upper_bound(all(a), q));
  //   };
  //   constexpr auto op = [](int a, int b) {
  //     return a + b;
  //   };
  //   return query<int, T, f, op, 0>(l, r, x);
  // }
  T kth_element_index(int l, int r, T x) const {
    return kth_element_index(1, 0, N-1, l, r, x);
  }

private:
  void build(const vector<T> &a, const vector<int> &b, int node, int tl, int tr) {
    if (tl == tr) {
      v[node].push_back(a[tl]);
      idx[node].push_back(b[tl]);
    } else {
      auto tm = tl + (tr - tl) / 2;
      build(a, b, 2*node, tl, tm);
      build(a, b, 2*node+1, tm+1, tr);
      merge(all(v[2*node]), all(v[2*node+1]), back_inserter(v[node]));
      merge(all(idx[2*node]), all(idx[2*node+1]), back_inserter(idx[node]));
    }
  }

  // template <typename R, typename Q, auto F, auto op, R id=R()>
  // R query(int node, int tl, int tr, int l, int r, Q x) const {
  //   static_assert(is_convertible_v<decltype(F), function<R(const vector<T> &, Q)>>, "F must be a function V(int, T)");
  //   static_assert(is_convertible_v<decltype(op), function<R(R, R)>>, "op must be a function T(T, T)");
  //   if (r < tl or tr < l) return id;
  //   if (l == tl and tr == r) {
  //     return F(v[node], x);
  //   }
  //
  //   auto tm = tl + (tr - tl) / 2;
  //   return op(query<R, Q, F, op, id>(2*node, tl, tm, l, min(r, tm), x), query<R, Q, F, op, id>(2*node+1, tm+1, tr, max(l, tm+1), r, x));
  // }

  int kth_element_index(int node, int tl, int tr, int l, int r, int k) const {
    if (tl == tr) return idx[node][0];

    int cnt = (int)(upper_bound(all(idx[2*node]), r) - lower_bound(all(idx[2*node]), l));

    auto tm = tl + (tr - tl) / 2;
    if (cnt > k)
      return kth_element_index(2*node, tl, tm, l, r, k);
    else
      return kth_element_index(2*node+1, tm+1, tr, l, r, k-cnt);
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (auto &x : v) cin >> x;

  MergeSortTree<int> mst(v);

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --r, --k;
    cout << v[mst.kth_element_index(l, r, k)] << '\n';
  }
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
