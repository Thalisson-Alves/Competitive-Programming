#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;
// Supports
// - find_by_order(idx): returns an iterator to the idx-th element (0-indexed)
// - order_of_key(key): returns the index of the key in the set

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x, --x;
  ordered_set<int> st;
  constexpr ll mod = 998244353;
  ll base = 0;
  for (auto x : a) {
    (base += st.size()-st.order_of_key(x)) %= mod;
    st.insert(x);
  }
  st.clear();
  ll res = 0, cur = 0, add = (k*(k-1ll)/2)%mod;
  (add *= fpow(2,mod-2,mod)) %= mod;
  for (int i = 0; i < n; i++) {
    (cur += st.size()-st.order_of_key(a[i])) %= mod;
    st.insert(a[i]);
    if (i >= k) {
      (cur += mod-st.order_of_key(a[i-k])) %= mod;
      st.erase(a[i-k]);
    }
    if (i>=k-1) (res += base - cur + add + mod) %= mod;
  }
  (res *= fpow(n-k+1,mod-2,mod)) %= mod;
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
