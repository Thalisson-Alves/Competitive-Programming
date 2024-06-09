#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  multiset<ll> pref, suf(a.begin(), a.end());
  ll sum_pref = 0, sum_suf = accumulate(a.begin(), a.end(), 0LL);

  for (auto x : a) {
    sum_pref += x;
    sum_suf -= x;
    pref.insert(x);
    suf.erase(suf.find(x));

    if (sum_pref < sum_suf) {
      auto dif = sum_suf - sum_pref;
      if (dif % 2 == 0 and suf.find(dif >> 1) != suf.end()) {
        cout << "YES\n";
        return;
      }
    } else if (sum_suf < sum_pref) {
      auto dif = sum_pref - sum_suf;
      if (dif % 2 == 0 and pref.find(dif >> 1) != pref.end()) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
