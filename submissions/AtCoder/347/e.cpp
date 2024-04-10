#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  set<int> st;
  vector<int> v(q), qs(q);
  for (int i = 0; i < q; i++) {
    cin >> qs[i];
    if (st.insert(qs[i]).second) {
      v[i] = (int)st.size();
    } else {
      v[i] = -(int)st.size();
      st.erase(qs[i]);
    }
  }

  vector<ll> res(n);
  vector<ll> last_remove(n);
  ll acc = 0;
  for (int i = q - 1; ~i; --i) {
    if (v[i] > 0) {
      res[qs[i]-1] += acc + v[i] - last_remove[qs[i] - 1];
      acc += v[i];
      last_remove[qs[i] - 1] = 0;
    } else {
      acc -= v[i] + 1;
      last_remove[qs[i] - 1] = acc;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i == n-1];
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
