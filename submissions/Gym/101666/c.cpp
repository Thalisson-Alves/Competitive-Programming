#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  set<ll> pref, st;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    set<ll> nxt;
    nxt.insert(x);
    st.insert(x);
    for (auto it = pref.rbegin(); it != pref.rend() and x > 1; it++) {
      nxt.insert(x = gcd(x, *it));
      st.insert(x);
    }
    swap(nxt, pref);
  }
  cout << st.size() << '\n';
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
