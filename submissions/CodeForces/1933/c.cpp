#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve()
{
  ll a, b, l;
  cin >> a >> b >> l;
  set<ll> st;
  for (ll x = 1; x <= l; x *= a) {
    for (ll y = x; y <= l; y *= b) {
      if (l%y==0) st.insert(l/y);;
    }
  }
  cout << st.size() << '\n';
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
