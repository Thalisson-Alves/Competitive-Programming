#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> struct MergeSortTreeBIT {
  int N;
  vector<ordered_multiset<T>> bit;

  MergeSortTreeBIT(int n) : N(n + 1), bit(N + 1) { }
  MergeSortTreeBIT(const vector<T> &arr) : MergeSortTreeBIT((int)arr.size()) {
    build(arr);
  }

  void build(const vector<T> &arr) {
    for (int i = 0; i < N - 1; i++)
      add(i, arr[i]);
  }

  void add(int i, T x) {
    for (++i; i <= N; i += (i & -i))
      bit[i].insert(x);
  }

  void update(int i, T old_value, T new_value) {
    for (++i; i <= N; i += (i & -i)) {
      bit[i].erase(bit[i].upper_bound(old_value));
      bit[i].insert(new_value);
    }
  }

  // number of elements in [0, i] less than x
  int query(int i, T x) {
    int res = 0;
    for (++i; i > 0; i -= (i & -i))
      res += (int)bit[i].order_of_key(x);
    return res;
  }
  // number of elements in [l, r] less than x
  int query(int l, int r, T x) {
    return query(r, x) - query(l-1, x);
  }

  T kth(int l, int r, int k, T lo=0, T hi=numeric_limits<T>::max()) {
    while (lo <= hi) {
      auto mid = midpoint(lo, hi);
      auto cnt = query(l, r, mid);
      if (cnt <= k) lo = mid+1;
      else hi = mid-1;
    }
    return hi;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  MergeSortTreeBIT<int> mst(v);

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      --l, --r;
      cout << (r - l + 1) - mst.query(l, r, x) << '\n';
    } else {
      int i, x;
      cin >> i >> x;
      --i;
      mst.update(i, v[i], x);
      v[i] = x;
    }
  }
}

int32_t main() {
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
