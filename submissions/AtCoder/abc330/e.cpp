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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  ordered_set<int> st;
  vector<int> hist(n);
  for (auto &x : a) {
    cin >> x;
    if (x < n) {
      hist[x]++;
      st.insert(x);
    }
  }
  auto mex = [&]() {
    if (st.empty()) return 0;
    int l = 0, r = n+1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      auto it = st.find_by_order(mid);
      if (it != st.end() and *it == mid) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l;
  };
  while (q--) {
    int i, x;
    cin >> i >> x;
    --i;

    if (a[i] < n and hist[a[i]]) {
      if (--hist[a[i]] == 0)
        st.erase(a[i]);
    }
    a[i] = x;
    if (x < n) {
      hist[x]++;
      st.insert(x);
    }
    cout << mex() << '\n';
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
