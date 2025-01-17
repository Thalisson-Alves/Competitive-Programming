#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; ll s;
  cin >> n >> s;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  vector<ll> suf(n+1), pref(n+1);
  partial_sum(rbegin(a), rend(a), rbegin(suf)+1);
  partial_sum(begin(a), end(a), begin(pref)+1);
  for (int i = 0; i < n; i++) {
    if (binary_search(begin(pref), end(pref), s-pref[i])) {
      cout << "Yes\n";
      return;
    }
  }
  if (s < pref.back()) {
    cout << "No\n";
    return;
  }
  // (s-pref[i]-suf[j]) % pref.back() == 0
  for (int i = 0; i < n; i++) {
    if (binary_search(rbegin(suf), rend(suf), ((s-pref[i])%pref.back()+pref.back())%pref.back())) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
