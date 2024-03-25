#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  set<int> a;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= k)
      a.insert(x);
  }

  ll sum = accumulate(a.begin(), a.end(), 0ll);;
  cout << (1 + k) * k / 2 - sum << '\n';
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
