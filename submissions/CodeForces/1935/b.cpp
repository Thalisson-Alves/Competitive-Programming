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

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> hist(n);
  for (auto &x : a) cin >> x, (x < n ? hist[x]++ : 0);
  int mex = n;
  for (int i = 0; i < n; i++) {
    if (hist[i] == 0) {
      mex = i;
      break;
    }
  }

  if (mex == 0) {
    cout << "2\n1 1\n2 " << n << '\n';
    return;
  }

  ordered_set<int> st;
  int res = -1;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
    auto it = st.find_by_order(mex-1);
    if (it != st.end() and *it == mex-1) {
      res = i;
      break;
    }
  }
  vector<int> rm(n);
  for (int i = res+1; i < n; i++) if (a[i] < n) {
    rm[a[i]]++;
  }
  int rmex;
  for (rmex = 0; rmex < n; rmex++) {
    if (!rm[rmex]) break;
  }
  if (rmex != mex) {
    cout << "-1\n";
  } else {
    cout << 2 << '\n';
    cout << "1 " << res+1 << '\n';
    cout << res+2 << ' ' << n << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
