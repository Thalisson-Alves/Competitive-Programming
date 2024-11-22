#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  using T = array<int, 10>;
  auto cmp = [&](const tuple<T, T, int> &a, const tuple<T, T, int> &b) {
    for (int i = 0; i < k; i++) {
      if (get<0>(a)[i] < get<1>(b)[i])
        return false;
    }
    return true;
  };
  set<tuple<T, T, int>, decltype(cmp)> st(cmp);
  while (n--) {
    tuple<T, T, int> v;
    {
      T arr;
      for (int i = 0; i < k; i++) cin >> arr[i];
      v = {arr, arr, 1};
    }
    auto it = st.lower_bound(v);
    while (it != st.end() and !cmp(v, *it)) {
      for (int i = 0; i < k; i++) {
        get<0>(v)[i] = min(get<0>(v)[i], get<0>(*it)[i]);
        get<1>(v)[i] = max(get<1>(v)[i], get<1>(*it)[i]);
      }
      get<2>(v) += get<2>(*it);
      it = st.erase(it);
    }
    st.insert(v);
    cout << get<2>(*st.begin()) << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
