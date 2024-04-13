#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i][0] >> v[i][1], v[i][2] = i;

  sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
    return make_pair(a[0], -a[1]) < make_pair(b[0], -b[1]);
  });

  vector<int> contain(n), contained(n);
  ordered_set<pair<int, int>> mn, mx;
  for (int i = 0; i < n; i++) {
    {
      const auto &[_, r, id] = v[i];
      contained[id] += int(mx.size() - mx.order_of_key({r, -1}));
      mx.insert({r, i});
    }
    {
      const auto &[_, r, id] = v[n-i-1];
      contain[id] += int(mn.order_of_key({r, n}));
      mn.insert({r, n-i-1});
    }
  }

  for (int i = 0; i < n; i++) cout << contain[i] << " \n"[i == n-1];
  for (int i = 0; i < n; i++) cout << contained[i] << " \n"[i == n-1];
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
